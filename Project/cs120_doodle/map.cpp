/*
File name : map.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) :sieun choi
Author(secondary) : Yoonki Kim ,hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include <doodle/doodle.hpp>
#include <iostream>

#include "Map.h"

#include "Game_DB.h"
#include "boundary.h"

using namespace doodle;




void Map::setup(std::vector<std::vector<int>>& map_info) {

	Position temp_tile_pos = { 0.0f, 0.0f };
	Tile temp_tile(temp_tile_pos.x, temp_tile_pos.y, 1);
	edges.clear();

	set_of_collide_obj.clear();
	for (unsigned int j = 0; j < Map_DB::map_column; j++) {

		for (unsigned int i = 0; i < Map_DB::map_row; i++) {


			switch (map_info[j][i]) {
			case 0:
				break;
			case 1: {
				temp_tile_pos = { static_cast<float>(i * Map_DB::rect_width) , static_cast<float>(j * Map_DB::rect_height) };
				temp_tile.sync_pos(temp_tile_pos);
				temp_tile.get_type(map_info[j][i]);
				temp_tile.sync_AABB();
				set_of_collide_obj.push_back(temp_tile);

				edge_convert(temp_tile);
				
				break;
			}
			}
		}
	}

}

void Map::setup_mage(std::vector<std::vector<int>>& Mage_info) {

	Position temp_tile_pos = { 0.0f, 0.0f };
	Tile temp_tile(temp_tile_pos.x, temp_tile_pos.y, 1);
	edges.clear();
	Position boss_tile_pos = { 0.0f, 0.0f };
	Tile boss_tile(boss_tile_pos.x, boss_tile_pos.y, 1);
	set_of_collide_obj.clear();
	set_of_boss_collide_obj.clear();
	for (unsigned int j = 0; j < Map_DB::map_column; j++) {

		for (unsigned int i = 0; i < Map_DB::map_row; i++) {


			switch (Mage_info[j][i]) {
			case 0:
				break;
			case 1: {
				temp_tile_pos = { static_cast<float>(i * Map_DB::rect_width) , static_cast<float>(j * Map_DB::rect_height) };
				temp_tile.sync_pos(temp_tile_pos);
				temp_tile.get_type(Mage_info[j][i]);
				temp_tile.sync_AABB();
				set_of_collide_obj.push_back(temp_tile);
				edge_convert(temp_tile);

				break;
			}
			case 3: {

				boss_tile_pos = { static_cast<float>(i * Map_DB::rect_width) , static_cast<float>(j * Map_DB::rect_height) };
				boss_tile.sync_pos(boss_tile_pos);
				boss_tile.get_type(Mage_info[j][i]);
				boss_tile.sync_AABB();
				set_of_boss_collide_obj.push_back(boss_tile);
				edge_convert(boss_tile);
				break;

			}
			}
		}
	}

}

void Map::draw() {
	int wallsize = static_cast<int>(set_of_collide_obj.size());
	for (int i = 0; i < wallsize; i++) {
		set_of_collide_obj[i].draw();
	}
	int wall_boss_size = static_cast<int>(set_of_boss_collide_obj.size());
	for (int i = 0; i < wall_boss_size; i++) {
		set_of_boss_collide_obj[i].draw();
	}
} 


void Map::edge_convert(Tile tile) {



	Vec tile_pos;
	tile_pos.x = tile.get_pos().x;
	tile_pos.y = tile.get_pos().y;
	Boundary temp_line(tile_pos.x, tile_pos.y, tile_pos.x + Map_DB::rect_width, tile_pos.y);
	edges.push_back(temp_line);
	temp_line = { tile_pos.x, tile_pos.y, tile_pos.x, tile_pos.y + Map_DB::rect_height };
	edges.push_back(temp_line);
	temp_line = { tile_pos.x, tile_pos.y + Map_DB::rect_height, tile_pos.x + Map_DB::rect_width, tile_pos.y + Map_DB::rect_height };
	edges.push_back(temp_line);
	temp_line = { tile_pos.x + Map_DB::rect_width, tile_pos.y + Map_DB::rect_height, tile_pos.x + Map_DB::rect_width, tile_pos.y };
	edges.push_back(temp_line);


}





