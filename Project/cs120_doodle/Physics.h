/*
File name : Physics.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
Author(secondary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include "Collision.h"
#include "Basic_Math.h"
#include "Tile.h"

class Physics {
protected:
	Position pos;
	float width;
	float height;

	Vector move_dir;
	Position next_pos;
	AABB collide_point;

	float move_speed;

	struct {
		bool isup;
		bool isdown;
		bool isleft;
		bool isright;
		bool iscollide;
	} move_status = {false, false, false, false, false};
public:
	Physics() {
		move_speed = 0.0f; width = 0; 
		height = 0; 
	}
public:
	void update_next_pos();
	void sync_pos();
	void sync_AABB();

	const Position& get_pos() {
		return this->pos;
	};

	void allocate_new_pos(const Position& new_pos) {
		this->pos = new_pos;
		this->next_pos = new_pos;
		sync_AABB();
	};

	void allocate_new_vec(const Vector& new_move_dir) {
		this->move_dir = new_move_dir;
	}

	void object_collision(std::vector<Tile>& set_of_objects);
	bool object_boss_collision(std::vector<Tile>& set_of_objects);
};

#endif