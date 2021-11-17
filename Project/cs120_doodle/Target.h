/*
File name : Target.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __TARGET_H__
#define __TARGET_H__

#include "Circle.h"

class Target : public Circle {
private:
	Position pos;
	float radius;

public:
	Target() { pos = { 0, 0 }, radius = 35.0f; }
	Position& get_pos() { return pos; };
	void sync_new_pos(const Position& new_pos);
	void draw(int& bullet_amount, bool is_parrying);
	void print_target_pos();
};

#endif
