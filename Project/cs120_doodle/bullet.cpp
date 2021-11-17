/*
File name : bullet.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include <doodle/doodle.hpp>
using namespace doodle;

#include "Bullet.h"

#include "Tile.h"
#include "Collision.h"

void Bullet::draw() {
	push_settings();
	no_fill();
	set_outline_width(3.0f);
	set_outline_color(HexColor{ 0x7B61F8FF });

	doodle::draw_ellipse(pos.x, pos.y, radius, radius);
	pop_settings();
}


//this function manage the bullet delete condition
bool Bullet::delete_condition(std::vector<Tile>& set_of_objects) {	

	unsigned int set_of_objects_size = static_cast<unsigned int>(set_of_objects.size());
	bool is_collision = false;
	for (unsigned int i = 0; i < set_of_objects_size; i++) {
		is_collision |= AABB_collision(collide_point, set_of_objects[i].get_collide_point());

	}
	if (is_collision) {
		is_collision = true;
	}

	if (this->pos.x < 0 || this->pos.x > Game_DB::width || this->pos.y < 0 || this->pos.y > Game_DB::height)	//when bullet is out of map(maybe not happend)
		is_collision = true;

	return is_collision;
}

//AABB min max sync to circle(AABB collision needs rectangel object)
void Bullet::circle_AABB_sync() {		
	this->collide_point.min = { this->next_pos.x - this->radius, this->next_pos.y + this->radius };
	this->collide_point.max = { this->next_pos.x + this->radius, this->next_pos.y - this->radius };
}
