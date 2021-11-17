/*
File name : Rectangle.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Basic_Math.h"

class Rect {
protected:
	float Width;
	float Height;
	Position pos;
public:
	Rect(float w, float h, float x, float y) : Width(w), Height(h)
	{
		pos.x = x;
		pos.y = y;
	}
	void draw();
};


#endif
