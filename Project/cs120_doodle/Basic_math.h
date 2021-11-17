/*
File name : Basic_Math.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __BASIC_MATH_H__
#define __BASIC_MATH_H__

#include <vector>

struct Position {
	float x= 0.0f;
	float y= 0.0f;
};

struct Vector {
 	float x = 0.0f;
 	float y = 0.0f;
};

float get_distance(const Position& a, const Position& b);

const Vector get_unit_vec(const Position& a, const Position& b);

Vector radian_to_unit_vec(float radian);

#endif