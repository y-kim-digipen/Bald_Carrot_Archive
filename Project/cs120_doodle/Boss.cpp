/*
File name : Boss.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : Yoonki Kim
“All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.”
*/
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Boss.h"


void Boss::setup(){

}


void Boss::script(Bullet_maker& bullet_shooter, const Position& player_pos) {

		move_script();
		std::srand(static_cast<unsigned int>(std::time(0)));
		int attack_type = 0;
	if (doodle::ElapsedTime > first_shoot_time) {
		if (static_cast<int>(doodle::ElapsedTime) % 5 <= 1 && life > 0) {	// every five seconds boss can shoot
			is_can_shoot = true;
		}
		else is_can_shoot = false;

		if (doodle::ElapsedTime > next_shooting_time&& is_can_shoot) {
			next_shooting_time = doodle::ElapsedTime + shooting_time_left; //this makes delay to shooting pattern
			attack_type = std::rand() % 6;								   //determine attack_type randomly
			shoot_script(attack_type, bullet_shooter, player_pos);
		}
	}
}

void Boss::shoot_script(unsigned int type, Bullet_maker& bullet_shooter, const Position& player_pos) {
	Bullet current_bullet;
	Position bullet_pos;
	Vector bullet_vec;
	int num = 0;
	float time_time = doodle::ElapsedTime;
	switch (type) {
	case 0:
		current_bullet.allocate_new_pos({ this->pos.x + this->width / 2,  this->pos.y + this->height / 2 });
		current_bullet.allocate_new_vec({ 0.0f, 1.0f });
		bullet_shooter.allocate_new_bullet(current_bullet);
		break;

	case 1:
		for (unsigned int i = 0; i < 4; i++) {
			current_bullet.allocate_new_pos({ this->pos.x + this->width / 2,  this->pos.y + this->height / 2 });
			bullet_vec = get_unit_vec({ player_pos.x + this->width / 2, player_pos.y + this->height / 2 }, { this->pos.x + this->width / 2,  this->pos.y + this->height / 2 });
			current_bullet.allocate_new_vec(bullet_vec);
			current_bullet.allocate_shoot_time(time_time + i * 0.3f);
			bullet_shooter.allocate_new_bullet(current_bullet);
		}
		
		break;


	case 2:

		for (unsigned int col = 0; col < 4; col++) {
			for (unsigned int row = 0; row < 10; row++) {

				switch (col) {
				case 0:		//each case means which side will bullet shooted
					bullet_pos = { Map_DB::rect_width + Player_DB::bullet_radius + row * (Game_DB::width - 2 * (Map_DB::rect_width - Player_DB::bullet_radius)) / 10 , Map_DB::rect_height + Player_DB::bullet_radius };
					bullet_vec = { 0.0f, 1.0f };
					break;

				case 1:
					bullet_pos = { Game_DB::width - (Map_DB::rect_width + Player_DB::bullet_radius) , Map_DB::rect_height + Player_DB::bullet_radius + row * (Game_DB::height - 2 * Map_DB::rect_height - Player_DB::bullet_radius) / 10 };
					bullet_vec = { -1.0f, 0.0f };
					break;

				case 2:
					bullet_pos = { Map_DB::width - Map_DB::rect_width - Player_DB::bullet_radius - row * (Game_DB::width - 2 * Map_DB::rect_width - Player_DB::bullet_radius) / 10, Game_DB::height - (Map_DB::rect_height + Player_DB::bullet_radius) };
					bullet_vec = { 0.0f, -1.0f };
					break;

				case 3:
					bullet_pos = { Map_DB::rect_width + Player_DB::bullet_radius , Map_DB::height - Map_DB::rect_height - Player_DB::bullet_radius - row * (Game_DB::height - 2 * Map_DB::rect_height - Player_DB::bullet_radius) / 10 };
					bullet_vec = { +1.0f, 0.0f };
					break;
						
				}

				current_bullet.allocate_shoot_time(time_time + (col * 10 + (row + 1)) * 0.1f);
				current_bullet.allocate_new_pos(bullet_pos);
				current_bullet.allocate_new_vec(bullet_vec);
				bullet_shooter.allocate_new_bullet(current_bullet);		//allocate to bullet control vector
				num++;
			}
		}
		break;

	case 3:

		for (unsigned int row = 0; row < 10; row++) {
			bullet_pos = { Map_DB::rect_width + 30 + row * (Game_DB::width - Map_DB::rect_width) / 10 , Map_DB::rect_height + Player_DB::bullet_radius };
			bullet_vec = { 0.0f, 1.0f };

			current_bullet.allocate_shoot_time(time_time + (row + 1) * 0.2f);
			current_bullet.allocate_new_pos(bullet_pos);
			current_bullet.allocate_new_vec(bullet_vec);
			bullet_shooter.allocate_new_bullet(current_bullet);
		}
		break;

	case 4:

		for (unsigned int index = 0; index < 100; index++) {
			bullet_pos = { Map_DB::width/2, Map_DB::height/2 };
			bullet_vec = radian_to_unit_vec((doodle::TWO_PI/20 + doodle::QUARTER_PI / 33) * index  + doodle::QUARTER_PI / 5);

			current_bullet.allocate_shoot_time(time_time + 1.0f + index * 0.03f);
			current_bullet.allocate_new_pos(bullet_pos);
			current_bullet.allocate_new_vec(bullet_vec);
			bullet_shooter.allocate_new_bullet(current_bullet);
		}

		break;

	case 5:
		for (unsigned int repeat = 0; repeat < 5; repeat++) {
			for (unsigned int index = 0; index < 20; index++) {
				bullet_pos = { Map_DB::width / 2, Map_DB::height / 2 };
				bullet_vec = radian_to_unit_vec((doodle::TWO_PI / 20 ) * index + doodle::QUARTER_PI / 5);

				current_bullet.allocate_shoot_time(time_time + 1.0f+ repeat * 0.5f);

				current_bullet.allocate_new_pos(bullet_pos);

				current_bullet.allocate_new_vec(bullet_vec);

				bullet_shooter.allocate_new_bullet(current_bullet);
			}
		}

		break;
	}




}

//manage boss moving
void Boss::move_script() {
	if (this->pos.x < 0 + Map_DB::rect_width) {
		this->move_status.isleft = false;
		this->move_status.isright = true;
		this->move_dir = { 1.0f, 0.0f };
	}
	else if (this->pos.x + this->width > Game_DB::width - Map_DB::rect_width) {
		this->move_status.isright = false;
		this->move_status.isleft = true;
		this->move_dir = { -1.0f, 0.0f };
	}

	if (this->life <= 0)
		this->next_pos = { -100.0f, -100.0f };
}

void Boss::draw() {
	doodle::push_settings();
	doodle::no_fill();
	doodle::set_outline_color(doodle::HexColor{ 0xA5D8F3FF });

	doodle::draw_rectangle(this->pos.x, this->pos.y, this->width, this->height);
	

	if (this->life > 0 && this->life < 100) {
		doodle::set_fill_color(doodle::HexColor{ 0x00FECAFF });
		doodle::draw_rectangle(this->pos.x, this->pos.y + this->life * (this->height / 100), this->width, this->height - this->life * (this->height / 100));
	}
	doodle::pop_settings();
}

//by using AABB collision manage boss condition
void Boss::hit_by_bullet(std::vector < Bullet >* player_bullets) {

	for (unsigned int i = 0; i < player_bullets->size(); i++) {
			if (AABB_collision(collide_point, player_bullets->at(i).get_collision_point())) {	//when AABB collision return true
			player_bullets->erase(player_bullets->begin() + i);
			life -= 10;
			break;

		}
	}
}

////////

void Tutorial_Boss::hit_by_bullet(std::vector < Bullet >* player_bullets) {

	for (unsigned int i = 0; i < player_bullets->size(); i++) {
		if (AABB_collision(collide_point, player_bullets->at(i).get_collision_point())) {	//when AABB collision return true
			player_bullets->erase(player_bullets->begin() + i);
			life -= 10;
			break;

		}
	}
}

void Tutorial_Boss::script(Bullet_maker& bullet_shooter) {
	if (doodle::ElapsedTime > next_shooting_time) {
		next_shooting_time = doodle::ElapsedTime + shooting_time_left; 
		shoot_script(bullet_shooter);
	}
}


void Tutorial_Boss::draw() {
	doodle::push_settings();
	doodle::no_fill();
	doodle::set_outline_color(doodle::HexColor{ 0xA5D8F3FF });

	doodle::draw_rectangle(this->pos.x, this->pos.y, this->width, this->height);

	/*std::cout << this->life << std::endl;*/



	if (this->life > 0 && this->life < 100) {
		doodle::set_fill_color(doodle::HexColor{ 0x00FECAFF });
		doodle::draw_rectangle(this->pos.x, this->pos.y + this->life * (this->height / 100), this->width, this->height - this->life * (this->height / 100));
	}

	if (this->life <= 0)
		this->life = 100;
	doodle::pop_settings();
}


void Tutorial_Boss::shoot_script(Bullet_maker& bullet_shooter) {
		Bullet current_bullet;
		current_bullet.allocate_new_pos({pos.x + width/2, pos.y + height/2});
		current_bullet.allocate_new_vec({ 1.0f, 0.0f });
		bullet_shooter.allocate_new_bullet(current_bullet);
}