/*
File name : ray.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "ray.h"
#include <doodle/doodle.hpp>


//draw ray
void Ray::draw(Player a, std::vector <Boundary>& edges)
{

	Vec startpoint;
	Vec mouse_position1;
	const float MouseX = static_cast<float>(doodle::get_mouse_x());
	const float MouseY = static_cast<float>(doodle::get_mouse_y());
	startpoint.x = a.get_pos().x + Player_DB::width / 2;
	startpoint.y = a.get_pos().y + Player_DB::height / 2;
	mouse_position1.x = MouseX; 
	mouse_position1.y = MouseY;
	if(onoff_light)
	round_light(edges, startpoint, mouse_position1);
}
 

void Ray::check_intercept(const Vec& position1, const Vec& position2, const Vec& position3, const Vec& position4) {

	if (Vec::Intersect(position1, position2, position3, position4))
		is_intercept = true;
	else is_intercept = false;
}

void Ray::update_pos(const Vec& position1, const Vec& position2, const Vec& position3, const Vec& position4) {
	if (is_intercept) {
		Vec c = Vec::GetIntersect(position1, position2, position3, position4);
		set_outline_color(HexColor{ 0xFFFFFF1F });
		draw_line(position3.x, position3.y, c.x, c.y);
	}
}


void Ray::round_light(const std::vector <Boundary>& walls, Vec& start_position, Vec& target_position) {
	Vec infinity_line;
	///LIGHT posidsdtion3 start, position4 infinity 
	set_outline_color(HexColor(0xFFFFFFFF));
	set_fill_color(HexColor(0xFFFFFFFF));
	smooth_drawing();
	draw_ellipse(start_position.x, start_position.y, 5.0f, 5.0f);
	std::vector<Vec> particles;

	float get_base_line = GetAngle(Vec(target_position.y - start_position.y, target_position.x - start_position.x));
	
	// shoot the line
	for (float i = 00.0f; i < 60.0f; i += 0.5f) {
		float a = -get_base_line + doodle::to_radians(i) + 1.0472f;//60 degrees
		particles.push_back(Vec::setAngle(a));
	}


	for (int j = 0; j < particles.size(); j++) {
		infinity_line = particles[j];
		Vec closest(float(Width / 2), float(Height / 2));
		float record = std::numeric_limits<float>::max();
		bool checking_close = false;
		// check near boundary
		for (int i = 0; i < walls.size(); i++) {
			Vec pt = Vec::GetIntersect_limit(walls[i].a, walls[i].b, start_position, infinity_line);
			if (pt.x != 0.0f && pt.y != 0.0f) {
				float d = Vec::distance(start_position, pt);
				if (d < record) {
					record = d;
					closest = pt;
					checking_close = true;
				}
			}
		}
		//draw
		if (checking_close) {
			push_settings();
			set_outline_color(HexColor{ 0xdc143c08 });
			smooth_drawing();
			set_outline_width(10.0f);
			doodle::draw_line(start_position.x, start_position.y, closest.x, closest.y);
			pop_settings();
			checking_close = false;
		}
	}




}

void Ray::onoff_system() {
	
	int timers = (static_cast<int>(doodle::ElapsedTime) % 15);
	if ( timers == 0) {
		onoff_light = true;
	}
	if (timers == 10) {
		onoff_light = false;
	}
	if (timers == 11) {
		onoff_light = true;
	}
	if (timers == 12) {
		onoff_light = false;
	}
	if (timers == 13)
	{
		onoff_light = true;
	}
	
}