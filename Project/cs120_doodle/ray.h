/*
File name : ray.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include "mathvector.h"

#include "Player.h"
#include "boundary.h"
#include <vector>



class Ray : public Vec {
private:


public:
	Vec position;
	Vec mouse_position;
	bool onoff_light = true;
	bool is_intercept = false;
public:
	void draw(Player a, std::vector <Boundary>&);

	void check_intercept(const Vec&, const Vec&, const Vec&, const Vec&);
	void update_pos(const Vec&, const Vec&, const Vec&, const Vec&);
	void round_light(const std::vector <Boundary>&, Vec&, Vec&);
	void onoff_system();
};