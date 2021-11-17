/*
File name : rectangle.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "doodle/doodle.hpp"

#include "Rectangle.h"

#include "Game_DB.h"

void Rect::draw() {
	doodle::set_fill_color(Map_DB::Wall_color);
	doodle::draw_rectangle(pos.x, pos.y, this->Width, this->Height);
}
