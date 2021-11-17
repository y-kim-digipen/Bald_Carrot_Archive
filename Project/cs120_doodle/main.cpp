/*
File name : main.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : sieun choi
Author(secondary) : Yoonki Kim ,hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "Game.h"

#include "doodle/doodle.hpp"

#include "Game_DB.h"

using namespace doodle;

int main(void)
{
	Game new_game;
	new_game.setup();

	Texture        DigipenSplash;
	DigipenSplash.LoadFromPNG("DigiPen_WHITE_1024px.png");
	set_texture_mode(RectMode::Center);
	
	int SplashFrame = 120;

	while (!is_window_closed() && SplashFrame > 0)
	{
		update_window();
		draw_texture(DigipenSplash, Game_DB::width/2.0f,Game_DB::height/2.0f,600,150);
		SplashFrame--;
	}

    while (!is_window_closed())
    {
		set_fill_color(HexColor{ 0x123456 });
		set_window_title("Bald Carrot in dark KMU");
        update_window();
        clear_background(Game_DB::background_color);
		
		new_game.declaraiton();
    }
    return 0;
}
