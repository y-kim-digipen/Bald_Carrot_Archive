/*
File name : Physics.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
Author(secondary) :hoseob.jeong
“All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.”
*/
#include <iostream>
#include <doodle/doodle.hpp>
#include "Physics.h"
#include "Tile.h"
#include "Collision.h"

//use next position to when it collide make it not move
void Physics::update_next_pos() {
	next_pos.x += move_dir.x * doodle::DeltaTime * 100 * move_speed;
	next_pos.y += move_dir.y * doodle::DeltaTime * 100 * move_speed;
}

void Physics::sync_pos() {
	pos = next_pos;
}

void Physics::sync_AABB() {
	collide_point.max = { next_pos.x + this->width, next_pos.y };
	collide_point.min = { next_pos.x , next_pos.y + this->height };
}

void Physics::object_collision(std::vector<Tile>& set_of_objects) {
	unsigned int set_of_objects_size = static_cast<unsigned int>(set_of_objects.size());
	bool is_collision = false;
	for (unsigned int i = 0; i < set_of_objects_size; i++) {
		is_collision |= AABB_collision(collide_point, set_of_objects[i].get_collide_point());

	}
	if (is_collision) {
		is_collision = true;
		next_pos = pos;
	}
}

bool Physics::object_boss_collision(std::vector<Tile>& set_of_objects) {
	unsigned int set_of_objects_size = static_cast<unsigned int>(set_of_objects.size());
	bool is_collision = false;
	for (unsigned int i = 0; i < set_of_objects_size; i++) {
		is_collision |= AABB_collision(collide_point, set_of_objects[i].get_collide_point());

	}
	if (is_collision) {
		return true;
	}

	return false;
}


