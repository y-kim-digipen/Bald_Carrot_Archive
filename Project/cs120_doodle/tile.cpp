/*
File name : tile.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
Author(secondary) :sieun choi
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "Tile.h"

#include "Game_DB.h"

using namespace doodle;

void Tile::draw() {

	push_settings();
	set_fill_color(HexColor(0x000000ff));
	no_outline();
	draw_rectangle(pos.x, pos.y, Map_DB::rect_width, Map_DB::rect_height);
	pop_settings();
}



void Tile::sync_pos(Position new_pos) {
	this->pos = new_pos;
}

void Tile::get_type(int tile_type) {
	this->type = tile_type;
}

void Tile::sync_AABB() {
	collide_point.max = { pos.x + Map_DB::rect_width, pos.y };
	collide_point.min = { pos.x , pos.y + Map_DB::rect_height };
}

