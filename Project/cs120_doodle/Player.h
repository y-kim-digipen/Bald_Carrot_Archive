/*
File name : Player.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Physics.h"
#include "Target.h"
#include "Bullet.h"
#include "Tile.h"

enum class Player_move {
	LEFT, RIGHT, UP, DOWN
};

class Player : public Physics {
private:
	Target target;

	std::vector<Bullet> ammo;
	std::vector<Bullet> shooted_bullet;

	int life;

	bool is_parrying = false;
	bool is_vulnerable = true;

	float parrying_time_left = 0.5f;
	float next_parrying_time = 0.0f;

	float invulnerable_time_left = 2.0f;
	float next_invulnerable_time = 0.0f;
public:
	Player(float x, float y, float width, float height, float accel_speed, int life) : Physics() {
		this->pos.x = x;
		this->pos.y = y;
		this->next_pos.x = x;
		this->next_pos.y = y;
		this->width = width;
		this->height = height;
		this->move_speed = accel_speed;
		this->life = life;
	}

public:
	void update_move_status(Player_move update_move_status);
	void update_stop_status(Player_move update_move_status);

	void make_max_health() {
		this->life = 4;
	}
	void draw_life();
	void accel();
	void sync_target_pos(const Position& mouse_position);
	Position& get_target_pos() {
		return target.get_pos();
	}

	int& get_life() {
		return this->life;
	}

	void set_pos(Position new_pos) {
		this->next_pos = new_pos;
		this->pos = new_pos;
	}
	

	void make_parrying_status();
	void parrying(std::vector < Bullet >* hostile_bullets);

	void get_ammo();
	//state initialization
	void ammo_init();
	void player_init();

	void shoot();
	void manage_shooted_bullets(std::vector<Tile>& set_of_objects);
	std::vector<Bullet>* get_setof_array();
	void hit_by_bullet(std::vector < Bullet >* hostile_bullets);
	void bullet_control(std::vector<Tile>& set_of_objects);

	void draw();


};

#endif