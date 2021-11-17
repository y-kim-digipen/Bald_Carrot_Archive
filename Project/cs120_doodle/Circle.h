/*
File name : Circle.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Basic_Math.h"

class Circle {
protected:
	Position pos;
	float radious = 4.0f;
public:
	void draw();
};

#endif
