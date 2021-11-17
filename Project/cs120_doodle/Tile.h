/*
File name : Tile.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Sieun Choi
Author(secondary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __TILE_H__
#define __TILE_H__

#include "Collision.h"
#include "Basic_Math.h"

enum class tile_type {
	WALL = 1
};

class Tile {
private:
	Position pos;
	AABB collide_point;
	int type;
public:
	Tile(float x, float y, int get_type) {
		pos = { x,y };
		type = get_type;
	}

	const AABB& get_collide_point() {
		return this->collide_point;
	}

	void sync_AABB();
	void draw();
	void get_type(int tile_type);
	const Position get_pos() {
		return pos;
	}
	const Position get_pos_val() {
		return pos;
	}
	void sync_pos(Position new_pos);

};




#endif 
