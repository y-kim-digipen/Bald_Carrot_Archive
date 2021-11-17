/*
File name : collision.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "Collision.h"


float get_distance(const Position& a, const Position& b) {
	return static_cast<float>(sqrt(static_cast<double>(powf((a.x - b.x), 2)) + static_cast<double>(powf((a.y - b.y), 2))));
}

const Vector get_unit_vec(const Position& a, const Position& b) {
	float distance_between = get_distance(a, b);
	return { (a.x - b.x) / distance_between, (a.y - b.y) / distance_between };
}

bool AABB_collision(const AABB& a_obj, const AABB& b_obj) {

	if (b_obj.max.x > a_obj.min.x&& a_obj.max.x > b_obj.min.x)
		if (b_obj.max.y < a_obj.min.y && a_obj.max.y < b_obj.min.y)
			return true;

	return false;

}

Vector radian_to_unit_vec(float radian) {
	return Vector{ static_cast<float>(cos(radian)),  static_cast<float>(sin(radian)) };
}

bool circle_collision(const Position& a_obj, const Position& b_obj, float radius) {
	return (get_distance(a_obj, b_obj) < radius);

}