/*
File name : Collision.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "Basic_Math.h"

struct AABB {
	Position min = { 0.0f, 0.0f };
	Position max = { 0.0f, 0.0f };
};

bool AABB_collision(const AABB& a_obj, const AABB& b_obj);

bool circle_collision(const Position& a_obj, const Position& b_obj, float radius);

#endif
