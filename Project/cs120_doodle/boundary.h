/*
File name : boundary.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#pragma once
#include <doodle/doodle.hpp>
#include "mathvector.h"
#include "Player.h"
using namespace doodle;
class Boundary : public Vec {
private:
	int close_time = 5;

public:
	Boundary(float temp1X, float temp1Y, float temp2X, float temp2Y);
	Vec a;
	Vec b;
	int state = 1;
	float firetime = 2.0f;
	float firefinshtime = 0.0f;
	int left_cracker = 2; 
	bool firecrack = false;
	bool cheatcode = false;


	void left_firebullet();
	void Draw();
	void firecracker_system();
	void cheat_map();
	void fire();
	void boss_draw();
	void draw_firecrackerleft(Player player);
};

void drawing_firesystem(std::vector <Boundary>& boundarys, Boundary&);
enum Cheatonoff {

	ON, OFF

};