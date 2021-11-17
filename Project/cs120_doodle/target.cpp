/*
File name : target.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include <iostream>
#include <doodle/doodle.hpp>

#include "Target.h"

using namespace doodle;

void Target::draw(int& bullet_amount, bool is_parring) {
	int available_bullet = bullet_amount;
	push_settings();
	set_outline_width(2.0f);
	if (is_parring)
		set_outline_color(HexColor{ 0xEA0A8Eff });
	else
		set_outline_color(HexColor{ 0xEA0A8E70 });

	HexColor fill_color = 0xff78cbFF;

	if (is_parring == false)
		fill_color = 0xff78cb70;

	set_fill_color(HexColor{ 0x000000FF });
	if (available_bullet >= 1)
		set_fill_color(HexColor{ fill_color });
	else
		set_fill_color(HexColor{ 0x000000FF });
	draw_triangle(pos.x, pos.y, pos.x - 17.3f, pos.y + 10.0f, pos.x + 17.3f, pos.y + 10.0f);
	if (available_bullet >= 2)
		set_fill_color(HexColor{ fill_color });
	else
		set_fill_color(HexColor{ 0x000000FF });
	draw_triangle(pos.x, pos.y, pos.x - 17.3f, pos.y + 10.0f, pos.x , pos.y - 20.0f);
	if (available_bullet >= 3)
		set_fill_color(HexColor{ fill_color });
	else
		set_fill_color(HexColor{ 0x000000FF });
	draw_triangle(pos.x, pos.y, pos.x + 17.3f, pos.y + 10.0f, pos.x , pos.y - 20.0f);
	pop_settings();
}

void Target::sync_new_pos(const Position& new_pos) {
	this->pos = new_pos;
}

void Target::print_target_pos() {
	std::cout << pos.x << "\t" << pos.y << std::endl;
}