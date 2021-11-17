/*
File name : Bullet_Set.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/

#ifndef __BULLET_SET_H__
#define __BULLET_SET_H__

#include "Basic_Math.h"
#include "Bullet.h"
#include "Tile.h"

class Bullet_maker {
private:
	std::vector<Bullet> bullet_shooter;
	bool shoot_trigger = false;
	float time_left = 2.0f;
	float this_time = 0.0f;

public:
	void delete_bullet(const unsigned int index);

	void manage(std::vector<Tile>& set_of_objects);

	void allocate_new_bullet(Bullet& new_bullet) {
		bullet_shooter.push_back(new_bullet);
	}

	std::vector<Bullet> get_array();
	void init() {
		bullet_shooter.clear();
	}
	void shoot();
	void update();
	void draw_bullet();



	std::vector<Bullet>* get_setof_array();
};


#endif 
