/*
File name : mathvector.h
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#ifndef __MATHVECTOR_H__
#define __MATHVECTOR_H__

class Vec {


public:
	float x;
	float y;

	Vec();
	Vec(float, float);
	void print();
	static void printout(const Vec&);
	//two vector interactive
	Vec operator+(const Vec&) const;
	Vec operator-(const Vec&) const;
	Vec operator*(const Vec&) const;
	Vec operator/(const Vec&) const;

	//check the closer and further from the origin
	bool operator>(const Vec&) const;
	bool operator<(const Vec&) const;
	bool operator<=(const Vec&) const;
	bool operator>=(const Vec&) const;
	bool operator==(const Vec&) const;


	// negative value
	Vec operator-() const;

	//scalar
	Vec operator*(const float&) const;
	Vec operator/(const float&) const;

	static float Dotproduct(const Vec&, const Vec&);
	static float Crossproduct(const Vec&, const Vec&);
	static float Magnitude(const Vec&);
	//¼öÁ÷
	static Vec perpendicular(const Vec&);
	static bool Intersect(const Vec&, const Vec&, const Vec&, const Vec&);
	static Vec unitvector(const Vec&);
	static Vec GetIntersect(const Vec&, const Vec&, const Vec&, const Vec&);
	static Vec GetIntersect_limit(const Vec&, const Vec&, const Vec&, const Vec&);

	static float GetAngle(const Vec&);
	static float getAngleDeg(const Vec&);
	static Vec setAngle(const float&);
	static Vec setAngleDeg(float&);
	static float distance(Vec&, Vec&);
};

#endif