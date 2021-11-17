/*
File name : Boss.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __BOSS_H__
#define __BOSS_H__

#include "Physics.h"
#include "Basic_Math.h"
#include "Bullet_Set.h"


class Boss : public Physics{
private:

	int life;

	bool is_available = false;
	bool is_can_shoot = false;

	float shooting_time_left = 1.5f;
	float next_shooting_time = 0.0f;

	float action_time_left = 3.0f;
	float next_action_time = 0.0f;

	float first_shoot_time = 0.0f;

	std::vector<Tile> boss_kill_tile;
 
public:
	Boss(float x, float y, float width, float height, float move_speed, int life) : Physics() {
		this->pos.x = x;
		this->pos.y = y;
		this->next_pos.x = x;
		this->next_pos.y = y;
		this->width = width;
		this->height = height;
		this->move_speed = move_speed;
		this->life = life;
		this->move_dir = { 1.0f, 0.0f };
	}

	int& boss_life() {

		return this->life;
	}



	void set_pos(Position new_pos) {
		this->pos = new_pos;
		this->next_pos = new_pos;
	}

	void get_first_shoot_time(float time) {
		this->first_shoot_time = time;
	}


	void setup(); 
	void make_shoot() {
		this->is_can_shoot = true;
	}
	void move_script();
	void script(Bullet_maker& bullet_shooter, const Position& player_pos);
	void draw();


	void hit_by_bullet(std::vector < Bullet >* hostile_bullets);
	void shoot_script(unsigned int type, Bullet_maker& bullet_shooter, const Position& player_pos);


};

class Tutorial_Boss : public Physics {
private:

	int life;

	bool is_available = false;
	bool is_can_shoot = false;

	float shooting_time_left = 5.0f;
	float next_shooting_time = 0.0f;



public:

	Tutorial_Boss(float x, float y, float width, float height, float move_speed, int life) : Physics() {
		this->pos.x = x;
		this->pos.y = y;
		this->next_pos.x = x;
		this->next_pos.y = y;
		this->width = width;
		this->height = height;
		this->move_speed = move_speed;
		this->life = life;
		this->move_dir = { 0.0f, 0.0f };
	}


	int& boss_life() {

		return this->life;
	}


	void script(Bullet_maker& bullet_shooter);

	void set_pos(Position new_pos) {
		this->pos = new_pos;
		this->next_pos = new_pos;
	}

	void make_shoot() {
		this->is_can_shoot = true;
	}
	void draw();
	void hit_by_bullet(std::vector < Bullet >* hostile_bullets);
	void shoot_script(Bullet_maker& bullet_shooter);


};


#endif