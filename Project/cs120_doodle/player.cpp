/*
File name : player.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
“All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.”
*/
#include <doodle/doodle.hpp>
#include <iostream>
#include <string>

using namespace doodle;

#include "Player.h"

void Player::update_move_status(Player_move update_move_status) {
	switch (update_move_status) {
	case Player_move::LEFT: 
		move_status.isleft = true;
		break;
	case Player_move::RIGHT:
		move_status.isright = true;
		break;
	case Player_move::UP:
		move_status.isup = true;
		break;
	case Player_move::DOWN:
		move_status.isdown = true;
		break;
	}
}

void Player::update_stop_status(Player_move update_move_status) {
	switch (update_move_status) {
	case Player_move::LEFT:
		move_status.isleft = false;
		break;
	case Player_move::RIGHT:
		move_status.isright = false;
		break;
	case Player_move::UP:
		move_status.isup = false;
		break;
	case Player_move::DOWN:
		move_status.isdown = false;
		break;
	}
}

void Player::draw_life() {
	push_settings();
	set_fill_color(HexColor{ 0x3CE664FF });
	draw_rectangle(pos.x, pos.y + height + height / 5, width / 4 * life, height / 5);


	pop_settings();
}

void Player::accel() {

	move_dir = { 0.0f, 0.0f };

	if (move_status.isleft)	move_dir.x -= move_speed;
	if (move_status.isright) move_dir.x += move_speed;
	if (move_status.isup) move_dir.y -= move_speed;
	if (move_status.isdown) move_dir.y += move_speed;

}

void Player::make_parrying_status() {
	if(is_parrying == false) is_parrying = true;
}

void Player::sync_target_pos(const Position& mouse_position) {
	target.sync_new_pos(mouse_position);
}


void Player::draw() {

	int bullet_size = static_cast<int>(ammo.size());


	push_settings();
	no_outline();
	draw_life();
	if (is_vulnerable == false) {
		set_outline_width(3.0f);

		set_outline_color(Player_DB::Player_invicible_color);
		no_fill();

		draw_rectangle(pos.x, pos.y, Player_DB::width, Player_DB::height);
	}

	if (is_parrying && is_vulnerable) {
		set_fill_color(HexColor{ Player_DB::Player_parrying_color });
	}
	else
		set_fill_color(Player_DB::Player_color);


	no_outline();
	set_outline_width(15.0f);
	draw_ellipse(pos.x + width / 2, pos.y + height / 2, width, height);

	set_fill_color(HexColor{ 0x000000FF});
	draw_ellipse(pos.x + width / 2, pos.y + height / 2, width * 4 / 5, height * 4 / 5);
	pop_settings();


	for (unsigned int i = 0; i < shooted_bullet.size(); i++) {
		shooted_bullet[i].draw();
	} 

	target.draw(bullet_size, is_parrying);
}


void Player::get_ammo() {
	Bullet bullet;
	if(ammo.size() < 3)		//player cannot get bullet over 3
	ammo.push_back(bullet);
}



void Player::ammo_init() {

	Bullet bullet;
	ammo.clear();

}

void Player::player_init() {

	this->life = 5;
	this->pos.x = Game_DB::width / 2.0f;
	this->pos.y = Game_DB::height / 2.0f;

}



void Player::shoot() {
	if (ammo.size() > 0) {
		Bullet current_bullet;
		Position center_pos{pos.x + width/2, pos.y + height/2};
		current_bullet.allocate_new_pos(center_pos);
		current_bullet.allocate_new_vec(get_unit_vec(get_target_pos(), center_pos));
		ammo.pop_back();
		shooted_bullet.push_back(current_bullet);
	}
}

//this manage player's shooted bullets
void Player::manage_shooted_bullets(std::vector<Tile>& set_of_objects) {
	unsigned int shooted_bullet_size = static_cast<unsigned int>(shooted_bullet.size());
	for (unsigned int i = 0; i < shooted_bullet_size; i++) {
		shooted_bullet[i].update_next_pos();
		shooted_bullet[i].sync_pos();
	}
	for (unsigned int i = 0; i < shooted_bullet_size; i++)
		if (shooted_bullet[i].delete_condition(set_of_objects))
			shooted_bullet.erase(shooted_bullet.begin() + i);
}

//manage catching status
void Player::parrying(std::vector < Bullet >* hostile_bullets) {
	if (ElapsedTime > next_parrying_time) {		//when parrying time is over
		next_parrying_time = ElapsedTime + parrying_time_left;
		is_parrying = false;		//make it not catching
	}
	if (is_parrying) {

		for (unsigned int i = 0; i < hostile_bullets->size(); i++) {
			if (circle_collision({ pos.x + width / 2, pos.y + height / 2 }, hostile_bullets->at(i).get_this_pos(), width / 2)) {
				if(is_vulnerable)	//can catch bullet when it is vulnerable status
				get_ammo();

				hostile_bullets->erase(hostile_bullets->begin() + i);		//when player can catch the bullet if collision works erase the hostile bullet

				is_parrying = false;
			}
		}
	}
}

std::vector<Bullet>* Player::get_setof_array() {
	return &shooted_bullet;
}

void Player::hit_by_bullet(std::vector < Bullet >* hostile_bullets) {
	if (is_vulnerable == false) 
		if (ElapsedTime > next_invulnerable_time) 
			is_vulnerable = true;
	
	if (is_parrying == false)

		for (unsigned int i = 0; i < hostile_bullets->size(); i++) {
			
			if (circle_collision({ pos.x + width / 2, pos.y + height / 2 }, hostile_bullets->at(i).get_this_pos(), width / 2) && is_vulnerable == true) {
				is_vulnerable = false;
				next_invulnerable_time = ElapsedTime + invulnerable_time_left;

				hostile_bullets->erase(hostile_bullets->begin() + i);

				life--;
				break;
			}
		}
}

void Player::bullet_control(std::vector<Tile>& set_of_objects) {
	for (unsigned int i = 0; i < shooted_bullet.size(); i++) {
		shooted_bullet[i].circle_AABB_sync();
		if (shooted_bullet[i].delete_condition(set_of_objects))
			shooted_bullet.erase(shooted_bullet.begin() + i);
	}
}

