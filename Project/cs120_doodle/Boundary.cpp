/*
File name : Boundary.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include"boundary.h"

//intitiize the boundary
Boundary::Boundary(float temp1X, float temp1Y, float temp2X, float temp2Y) {
	a = Vec(temp1X, temp1Y);
	b = Vec(temp2X, temp2Y);

}

//boundary draw
void Boundary::Draw() {
	push_settings();
	set_outline_color(HexColor{ 0xFFFFFFFF });
	draw_line(a.x, a.y, b.x, b.y);
	pop_settings();
}

//fire cracker random least 2 seconds
void Boundary::firecracker_system() {
	
		if (doodle::ElapsedTime > firefinshtime)
		{
			firefinshtime = doodle::ElapsedTime + firetime;
			firecrack = false;
	}

}
//firecracker is fire.
void Boundary::fire() {
	firecrack = true;

}

//how many firecracker left.
void Boundary::left_firebullet() {
	if (left_cracker > 0) {
		fire();
		left_cracker--;
	}

}

//draw the fire crackers 
void drawing_firesystem(std::vector <Boundary>& boundarys, Boundary&boundary) {
	if(boundary.cheatcode)
	for (int i = 0; i < boundarys.size(); i++) {
		boundarys[i].Draw();
	}
	if(boundary.firecrack)
		for (int i = 0; i < boundarys.size(); i++) {
			boundarys[i].Draw();
		}
}
// if boss_stage open, draw 
void Boundary::boss_draw() {
	cheatcode = true;

}
void Boundary::draw_firecrackerleft(Player player) {
	push_settings();
      float position_x =  player.get_pos().x;
	  float position_y = player.get_pos().y;
	  for (int i = 0; i < Boundary::left_cracker; i++) {
		  set_fill_color(HexColor{ 0xfc0324ff });
		  draw_rectangle(position_x + i * 20.0f, position_y - 10.0f, 5.0f, 5.0f);
	  }
	  pop_settings();
}

// cheat code
void Boundary::cheat_map() {

	switch (state) {
	case ON:
		cheatcode = true;
		state = OFF;
		break;
	case OFF:
		cheatcode = false;
		state = ON;
		break;
	}
}