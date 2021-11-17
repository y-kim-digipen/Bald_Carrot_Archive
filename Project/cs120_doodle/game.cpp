/*
File name : game.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) :sieun choi
Author(secondary) : Yoonki Kim , hoseob.jeong
��All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.��
*/
#include <iostream>
#include <doodle/doodle.hpp>

using namespace doodle;

#include "Game.h"
#include "Map.h"

#include "Bullet_Set.h"
#include "Player.h"
#include "Boss.h"
#include "ray.h"
#include "boundary.h"
void keyPressed(KeyboardButtons button);
void keyReleased(KeyboardButtons button);

class Physics;
Player player(Map_DB::rect_width, Map_DB::rect_height, Player_DB::width, Player_DB::height, Player_DB::accel_speed, 4);
Map map;
Ray ray;
Boundary boundary(0.0f,0.0f,0.0f,0.0f);
Game game;

class Mousemove {
private:
	Position pos{ 0.0f,0.0f };
public:
	void setup() {
		set_callback_mouse_moved([this](int x, int y) { OnMouseMoved(x, y); });
		set_callback_mouse_pressed([this](MouseButtons b) { OnMousePressed(b); });
		set_callback_mouse_released([this](MouseButtons b) { OnMouseReleased(b); });
	}
	void OnMouseMoved(int mouse_x, int mouse_y) noexcept
	{
		Position mouse_pos = { static_cast<float>(mouse_x), static_cast<float>(mouse_y) };
		player.sync_target_pos(mouse_pos);
	}
	void OnMousePressed(MouseButtons button) noexcept
	{
		if (button == MouseButtons::Right) player.make_parrying_status();
	}
	void OnMouseReleased(MouseButtons button) noexcept
	{
		if (button == MouseButtons::Left) player.shoot();
	}
};

Mousemove mouse;
static Bullet_maker bullet_maker;
Boss first_boss(static_cast<float>(Game_DB::width/2), 60.0f, Boss_DB::First::width, Boss_DB::First::height, Boss_DB::First::move_speed, 100);
Tutorial_Boss tuto_boss(static_cast<float>(Game_DB::width / 7), static_cast<float>(Game_DB::height * 4 / 5), Boss_DB::First::width, Boss_DB::First::height, 0.0f, 100);

void Game::declaraiton() {

	game.update();
	game.change_state();


	switch (stage) {
		//main menu
	case Mainmenu:
		game.mainmenu();
		break;
		//first stage
	case stage1:
		game.draw();
		break;
		//boss bang
	case stage2:
		game.Boss_Bullet();
		game.Boss(); 
		break;
	case Gameover:
		game.GameOver();
		game.state_init();
		break;
	case Clear:
		game.clear();
		game.state_init();
		break;
	case tutorial:
		game.Tutorial();
		break;

	}
}

void Game::setup() {

	show_cursor(false);
	std::cout << "Hello carrot!\n";
	create_window(Game_DB::width, Game_DB::height);

	set_frame_of_reference(LeftHanded_OriginTopLeft);
	set_callback_key_pressed(&keyPressed);
	set_callback_key_released(&keyReleased);
	mouse.setup();
	
	

}

void Game::Tutorial() {

	player.make_max_health();
	map.setup(Map_DB::tuto_info);

	
	tuto_boss.sync_AABB();
	tuto_boss.script(bullet_maker);
	tuto_boss.hit_by_bullet(player.get_setof_array());



	bullet_maker.update();
	bullet_maker.manage(map.get_set_of_collide_obj());
	bullet_maker.draw_bullet();

	map.draw();
	drawing_firesystem(map.get_edges(), boundary);
	ray.draw(player, map.get_edges()); 
	player.draw();
	push_settings();
	set_fill_color(HexColor{ 0xffffff0f });
	set_font_size(30);
	draw_text("Tutorial Stage", Width / 5.0f, Height / 5.0f);
	set_font_size(20);
	draw_text(" W : UP\n S : DOWN\n A : LEFT\n D : RIGHT\n", Width / 2.0f, 2 * Height / 5.0f);

	draw_text("Bullet catching : RIGHT MOUSE\nShoot : LEFT MOUSE\nFIRECRACKER : F", Width /4.0f, 4 * Height /5.0f);
	draw_text("Press space to skip the stage", Width / 4.0f, 5 * Height / 5.0f);

	pop_settings();
	
	boundary.draw_firecrackerleft(player);

	tuto_boss.draw();

}

void Game::update() {
	bullet_maker.draw_bullet();
	player.accel();
	player.update_next_pos();
	player.sync_AABB();
	player.object_collision(map.get_set_of_collide_obj());
	if (player.object_boss_collision(map.get_set_of_boss_collide_obj()))
	{
		if (stage == stage1) {
			first_boss.get_first_shoot_time(ElapsedTime + Boss_DB::First::first_shoot_delay);
			player.set_pos({ Map_DB::width_h, Map_DB::height_h });
			stage = stage2;
		}
	}
	player.sync_pos();
	player.manage_shooted_bullets(map.get_set_of_collide_obj());




	std::vector<Bullet>* hostile_bullet_set = bullet_maker.get_setof_array();
	player.parrying(hostile_bullet_set);
	player.hit_by_bullet(hostile_bullet_set);
	player.bullet_control(map.get_set_of_collide_obj());


	
	ray.onoff_system();
	//change to true
	boundary.firecracker_system();
	
}

void Game::state_init() {

	player.set_pos({ Map_DB::rect_width, Map_DB::rect_height });
	first_boss.set_pos({ (Game_DB::width / 2), 60.0f });
	player.ammo_init();
	boundary.left_cracker = 2;
	first_boss.boss_life() = 100;
	player.get_life() = 4;
	bullet_maker.init();
	boundary.cheatcode = false;
	tuto_boss.boss_life() = 100;
	


}

void Game::Boss_Bullet() {
	//
	std::vector<Bullet>* player_bullet_set = player.get_setof_array();
	first_boss.update_next_pos();
	first_boss.sync_AABB();
	first_boss.sync_pos();
	first_boss.hit_by_bullet(player_bullet_set);
	first_boss.script(bullet_maker, player.get_pos());
	first_boss.make_shoot();
	//
	bullet_maker.manage(map.get_set_of_collide_obj());
	bullet_maker.update();
}

void Game::draw() {
	
	push_settings();
	set_font_size(20);
	set_fill_color(HexColor{0x64c840ff});
	draw_text("EXIT",580.0f,600.0f);
	map.setup_mage(Map_DB::Mage_info);
	map.draw();
	drawing_firesystem(map.get_edges(),boundary);
	ray.draw(player, map.get_edges());
	player.draw();
	boundary.draw_firecrackerleft(player);
	pop_settings();
}

void Game::Boss() {

	
	map.setup(Map_DB::map_info);
	player.get_pos();
	map.draw();
	first_boss.draw();
	
	drawing_firesystem(map.get_edges(), boundary);
	boundary.boss_draw();
	player.draw();


}

void Game::change_state() {
	
	if (stage == stage2 && player.get_life() == 0)
		stage = Gameover;
	if (stage == stage2 && first_boss.boss_life() <= 0)
		stage = Clear;

}


void Game::GameOver() {

	push_settings();
	set_fill_color(HexColor{ 0xffffffff });
	set_font_size(40);
	draw_text("\tGame Over", Width / 4.0f, Height / 2.0f);
	set_font_size(20);
	draw_text("		Press ESC Key", Width / 4.0f  + 40.0f, Height - Height / 4.0f);

	pop_settings();
}


void Game::clear() {

	push_settings();
	set_fill_color(HexColor{ 0xffffffff });
	set_font_size(40);
	draw_text("\tClear", Width / 4.0f, Height / 2.0f);
	set_font_size(20);
	draw_text("		Press ESC Key", Width / 4.0f + 40.0f, Height - Height / 4.0f);

	pop_settings();
}




void Game::mainmenu() {

	push_settings();
	set_frame_of_reference(RightHanded_OriginBottomLeft);

	set_font_size(40);
	clear_background(HexColor{ 0x000000ff });
	//game name
	const std::string Game_name = "Bald Carrot in Dark KMU";
	push_settings();

	set_font_size(25);
	set_outline_color(HexColor{ 0xba7413ff });
	set_fill_color(HexColor{ 0xff9d26ff });

	draw_text(Game_name, Width / 4.0f, Height - Height / 4.0f);
	pop_settings();
	//bald carrot
	push_settings();

	const float CarrotPos_x = Width / 6.0f - 50.0f;
	const float CarrotPos_y = Height - 200.0f;

	set_fill_color(HexColor{ 0xeb8126ff });

	draw_triangle(Width - 80.0f, Height - Height / 4.0f
		, Width - 50.0f, Height - Height / 2.0f,
		Width - 20.0f, Height - Height / 4.0f);

	draw_triangle(Width / 6.0f - 70.0f, Height - Height / 4.0f
		, Width / 6.0f - 40.0f, Height - Height / 2.0f,
		Width / 6.0f - 20.0f, Height - Height / 4.0f);

	//tear 
	set_fill_color(HexColor{ 0xfc0324ff });
	no_outline();
	draw_ellipse(CarrotPos_x, CarrotPos_y - 15.0f, 6);
	draw_ellipse(CarrotPos_x + 15.0f, CarrotPos_y - 15.0f, 6);
	draw_ellipse(CarrotPos_x, CarrotPos_y - 25.0f, 6);
	draw_ellipse(CarrotPos_x + 15.0f, CarrotPos_y - 25.0f, 6);

	draw_ellipse(Width - Width / 14.0f, CarrotPos_y - 15.0f, 6);
	draw_ellipse(Width - Width / 18.0f, CarrotPos_y - 15.0f, 6);
	draw_ellipse(Width - Width / 14.0f, CarrotPos_y - 25.0f, 6);
	draw_ellipse(Width - Width / 18.0f, CarrotPos_y - 25.0f, 6);

	//eye 

	set_fill_color(HexColor{ 0x000000ff });
	draw_ellipse(CarrotPos_x, CarrotPos_y, 13);
	draw_ellipse(CarrotPos_x + 15.0f, CarrotPos_y, 13);

	draw_ellipse(Width - Width / 14.0f, CarrotPos_y, 13);
	draw_ellipse(Width - Width / 18.0f, CarrotPos_y, 13);
	//pupil
	set_fill_color(HexColor{ 0xfc0324ff });

	draw_ellipse(CarrotPos_x, CarrotPos_y, 6);
	draw_ellipse(CarrotPos_x + 15.0f, CarrotPos_y, 6);
	draw_ellipse(Width - Width / 14.0f, CarrotPos_y, 6);
	draw_ellipse(Width - Width / 18.0f, CarrotPos_y, 6);

	//Hair
	set_fill_color(HexColor{ 0x28a12aff });

	draw_rectangle(Width / 6.0f - 60.0f, Height - Height / 4.0f, 30.0f, 5.0f);
	draw_rectangle(Width - 70.0f, Height - Height / 4.0f, 40.0f, 5.0f);

	pop_settings();
	//button
	push_settings();
	set_outline_color(HexColor{ 0xba7413ff });
	set_fill_color(HexColor{ 0xc99e49ff });
	set_font_size(15);
	draw_text("Press 'space' to play game", Width / 3.0f, Height / 2.0f - Height / 4.0f);

	draw_text("Developed by Team Bald Carrot", Width /3.0f, Height / 8.0f - 50.0f);
	no_fill();
	draw_rectangle(Width / 3.0f, Height / 2.0f - Height / 4.0f, 250, 30);
	set_font_size(10);
	draw_text("All content  2019 DigiPen (USA) Corporation, all rights reserved.", Width / 3.0f - 20.0f, Height / 8.0f - 70.0f);

	pop_settings();

	pop_settings();


}


/////////////////////keyboard/////////////////////
void keyPressed(KeyboardButtons button) {
	if (button == KeyboardButtons::A)
		player.update_move_status(Player_move::LEFT);
	if (button == KeyboardButtons::D)
		player.update_move_status(Player_move::RIGHT);
	if (button == KeyboardButtons::W)
		player.update_move_status(Player_move::UP);
	if (button == KeyboardButtons::S)
		player.update_move_status(Player_move::DOWN);

	//statechange
	if (stage == Mainmenu && button == KeyboardButtons::Space)
	{
		player.set_pos({ Map_DB::width_h, Map_DB::height_h });
		stage = tutorial;
		
	}
	else if (stage == tutorial && button == KeyboardButtons::Space)
	{
		player.set_pos({ Map_DB::rect_width, Map_DB::rect_height });
		bullet_maker.init();
		stage = stage1;
		boundary.left_cracker = 2;
		player.get_life() = 4;

	}
	if (stage == Gameover && button == KeyboardButtons::Escape)
		stage = Mainmenu;
	if (stage == Clear && button == KeyboardButtons::Escape)
		stage = Mainmenu;

	//cheatkey
	if (stage == stage1 && button == KeyboardButtons::Escape)
	{
		first_boss.get_first_shoot_time(ElapsedTime + Boss_DB::First::first_shoot_delay);
		player.set_pos({ Map_DB::width_h, Map_DB::height_h });
		stage = stage2;

	}
	else if (stage == stage2 && button == KeyboardButtons::Escape)
	{
		game.state_init();
		stage = Mainmenu;
	}



}

void keyReleased(KeyboardButtons button) {
	if (button == KeyboardButtons::A)
		player.update_stop_status(Player_move::LEFT);
	if (button == KeyboardButtons::D)
		player.update_stop_status(Player_move::RIGHT);
	if (button == KeyboardButtons::W)
		player.update_stop_status(Player_move::UP);
	if (button == KeyboardButtons::S)
		player.update_stop_status(Player_move::DOWN);
	if (button == KeyboardButtons::_9)
		boundary.cheat_map();
	if (button == KeyboardButtons::F)
		boundary.left_firebullet();
}
