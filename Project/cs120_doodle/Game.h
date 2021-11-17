/*
File name : Game.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : sieun choi
Author(secondary) : Yoonki Kim , hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __GAME_H__
#define __GAME_H__

inline unsigned int stage = 0;

class Game {

private:
	unsigned int state;

public:
	
	void declaraiton();
	void setup();
	void update();
	void draw();
	void clear();
	void mainmenu();
	void GameOver();
	void Boss();
	void change_state();
	void Tutorial();
	void Boss_Bullet();
	void state_init();

};

enum GameStage {

	Mainmenu,instruction,stage1,stage2,Gameover,Clear,tutorial
};
#endif