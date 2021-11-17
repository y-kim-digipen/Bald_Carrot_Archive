/*
File name : circle.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include <doodle/doodle.hpp>

#include "Circle.h"

void Circle::draw() {
	doodle::no_fill();
	doodle::set_outline_color(doodle::HexColor{ 0xE43526FF });
	doodle::draw_ellipse(pos.x, pos.y, this->radious, this->radious);
}
