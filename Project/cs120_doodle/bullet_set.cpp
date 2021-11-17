/*
File name : bullet_set.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "Bullet_Set.h"
#include <iostream>

//manage all the bulets delete condition
void Bullet_maker::manage(std::vector<Tile>& set_of_objects) {	
	//delete bullet if it is collide with walls
	for (unsigned int i = 0; i < bullet_shooter.size(); i++) {
		bullet_shooter[i].circle_AABB_sync();
		if (bullet_shooter[i].delete_condition(set_of_objects))
			delete_bullet(i);
	}
}

//manage all the shooting condition
void Bullet_maker::shoot() {
	Bullet current_bullet;
	current_bullet.allocate_new_pos({ static_cast<float>(Map_DB::width / 2), 50.0f });
	current_bullet.allocate_new_vec({ 0.0f, 1.0f });
	bullet_shooter.push_back(current_bullet);
}


//update it's own position and sync AABB position to it's own position
void Bullet_maker::update() {
	for (unsigned int i = 0; i < bullet_shooter.size(); i++) {
		if (doodle::ElapsedTime > bullet_shooter[i].get_shoot_time()) {
			bullet_shooter[i].update_next_pos();
			bullet_shooter[i].sync_pos();
		}
	}
}

void Bullet_maker::draw_bullet() {
	for (unsigned int i = 0; i < bullet_shooter.size(); i++) {

		bullet_shooter[i].draw();
	}
}


std::vector<Bullet>* Bullet_maker::get_setof_array() {
	return &bullet_shooter;
}

std::vector<Bullet> Bullet_maker::get_array() {
	return this->bullet_shooter;
}

void Bullet_maker::delete_bullet(const unsigned int index) {
	bullet_shooter.erase(bullet_shooter.begin() + index);
}