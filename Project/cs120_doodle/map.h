/*
File name : Map.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Sieun Choi
Author(secondary) : Yoonki Kim, hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __MAP_H__
#define __MAP_H__

#include "Basic_Math.h"
#include "mathvector.h"
#include "boundary.h"
#include "Tile.h"

class Map {
private:
	std::vector<std::vector<Tile>> map;
	std::vector<Tile> set_of_collide_obj;
	std::vector<Tile> set_of_boss_collide_obj;
	std::vector<Boundary> edges;
public:
	std::vector<Tile>& get_set_of_collide_obj() {
		return set_of_collide_obj;
	}
	std::vector<Tile>& get_set_of_boss_collide_obj() {
		return set_of_boss_collide_obj;
	}

	std::vector<Boundary>& get_edges() {
		return edges;
	}

	void setup(std::vector<std::vector<int>>& map_info);
	void setup_mage(std::vector<std::vector<int>>& Mage_info);
	void draw();
	void edge_convert(Tile tile);
};


#endif