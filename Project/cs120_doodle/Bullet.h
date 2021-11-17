/*
File name : Bullet.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Game_DB.h"
#include "Basic_Math.h"
#include "Physics.h"

enum class Bullet_Type {
	NORMAL, FAST, SLOW
};

class Bullet : public Physics {
private:
	float radius;
	Bullet_Type type;
	float shoot_time;
	
public:

	Bullet() {
		Physics::width = 5.0f, Physics::height = 5.0f, radius = Player_DB::bullet_radius,
			Physics::move_speed = Player_DB::bullet_speed, type = Bullet_Type::NORMAL,
			shoot_time = 0;
	}
	Bullet(float Time) {
		Physics::width = 5.0f, Physics::height = 5.0f, radius = Player_DB::bullet_radius,
			Physics::move_speed = Player_DB::bullet_speed, type = Bullet_Type::NORMAL,
			shoot_time = Time;
	}

	const float& get_shoot_time() const{
		return this->shoot_time;
	}

	const Position& get_this_pos() const {
		return this->pos;
	}

	const AABB& get_collision_point() const {
		return this->collide_point;
	}

	bool delete_condition(std::vector<Tile>& set_of_objects);

	void allocate_shoot_time(float time) {
		this->shoot_time = time;
	}
	void circle_AABB_sync();
	void draw();

};

#endif

