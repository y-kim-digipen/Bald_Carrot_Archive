/*
File name : mathvector.cpp
Game name : Bald Carrot in Dark KMU
the course name  : GAM100
the term : Fall 2019
Author(primary) : hoseob.jeong
¡°All content (C) 2019 DigiPen (USA) Corporation, all rights reserved.¡±
*/
#include <cmath>
#include <iostream>

#include "mathvector.h"

Vec::Vec() {
	x = 0.0f;
	y = 0.0f;
}

Vec::Vec(float tempX, float tempY) {
	x = tempX;
	y = tempY;
}

void Vec::print() {
	std::cout << "( " << x << ", " << y << " )" << std::endl;

}

void Vec::printout(const Vec& v) {
	std::cout << "( " << v.x << ", " << v.y << " )" << std::endl;
}

Vec Vec::operator+(const Vec& v) const {
	return Vec(x + v.x, y + v.y);
}
Vec Vec::operator-(const Vec& v) const
{
	return Vec(x - v.x, y - v.y);
}
Vec Vec::operator*(const Vec& v) const {

	return Vec(x * v.x, y * v.y);

}
Vec Vec::operator/(const Vec& v) const {
	return Vec(x / v.x, y / v.y);

}

bool Vec::operator>(const Vec& v) const
{
	return (x * x + y *  y) > (v.x * v.x + v.y * v.y);
}

bool Vec::operator<(const Vec& v) const {

	return (x * x + y * y) < (v.x * v.x + v.y * v.y);
}

bool Vec::operator>=(const Vec& v) const {
	return (x * x + y * y) > (v.x * v.x + v.y * v.y) || (x * x + y * y) == (v.x * v.x + v.y * v.y);
}

bool Vec::operator<=(const Vec& v) const {

	return  (x * x + y * y) < (v.x * v.x + v.y * v.y) || (x * x + y * y) == (v.x * v.x + v.y * v.y);
}

bool Vec::operator==(const Vec& v) const {
	return ((x == v.x) && (y == v.y));
}

Vec Vec::operator*(const float& scalar) const {
	return Vec(x * scalar, y * scalar);
}

Vec Vec::operator/(const float& scalar) const {
	return Vec(x / scalar, y / scalar);

}

float Vec::Dotproduct(const Vec& a, const Vec& b) {
	return ((a.x * b.x) + (a.y * b.y));

}

float Vec::Crossproduct(const Vec& a, const Vec& b) {

	return ((a.x * b.y) - (b.x * a.y));

}

float Vec::Magnitude(const Vec& v) {
	return sqrt((v.x * v.x) + (v.y * v.y));
}


Vec Vec::unitvector(const Vec& v) {

	float magnitude = Magnitude(v);
	return Vec(v.x / magnitude, v.y / magnitude);
}

Vec Vec::perpendicular(const Vec& v) {
	return Vec(v.y, -v.x);

}

bool Vec::Intersect(const Vec& a1, const Vec& a2, const Vec& b1, const Vec& b2)
{
	Vec p = a1;
	Vec r = a2 - a1;
	Vec q = b1;
	Vec s = b2 - b1;

	float t = Crossproduct((q - p), s) / Crossproduct(r, s);
	float u = Crossproduct((q - p), r) / Crossproduct(r, s);
	return (0.0f <= t && t <= 1.0f) &&
		(0.0f <= u);
}

Vec Vec::GetIntersect_limit(const Vec& a1, const Vec& a2, const Vec& b1, const Vec& b2) {
	Vec p = a1;
	Vec r = a2 - a1;
	Vec q = b1;
	Vec s = b2 - b1;

	float t = Crossproduct((q - p), s) / Crossproduct(r, s);
	float u = Crossproduct((q - p), r) / Crossproduct(r, s);

	Vec cross;
	if (0.0f <= t && t <= 1.0f && 0.0f <= u) {

		cross.x = a1.x + t * (a2.x - a1.x);
		cross.y = a1.y + t * (a2.y - a1.y);
		return cross;
	}
	return Vec();
}



Vec Vec::GetIntersect(const Vec& a1, const Vec& a2, const Vec& b1, const Vec& b2)
{
	float valueX = (a1.x * a2.y - a1.y * a2.x) * (b1.x - b2.x) - (b1.x * b2.y - b1.y * b2.x) * (a1.x - a2.x);
	float valueY = (a1.x * a2.y - a1.y * a2.x) * (b1.y - b2.y) - (b1.x * b2.y - b1.y * b2.x) * (a1.y - a2.y);
	float undervalue = (a1.x - a2.x) * (b1.y - b2.y) - (a1.y - a2.y) * (b1.x - b2.x);

	return Vec(valueX / undervalue, valueY / undervalue);
}

float Vec::GetAngle(const Vec& v) {
	return atan2(v.y, v.x);

};

float Vec::getAngleDeg(const Vec& v) {
	return atan2(v.y, v.x) * 57.2957f;

};

Vec Vec::setAngle(const float& a) {

	Vec v;
	v.x = 100000000000000.0f;
	v.y = 0.0f;
	float length = sqrt(v.x * v.x + v.y * v.y);
	v.x = cos(a) * length;
	v.y = sin(a) * length;

	return Vec(v.x, v.y);
};

Vec Vec::setAngleDeg(float& a) {
	Vec v;
	v.x = 10.0f;
	v.y = 0.0f;
	float length = sqrt(v.x * v.x + v.y * v.y);
	a *= 0.0174532925f;
	v.x = cos(a) * length;
	v.y = sin(a) * length;

	return Vec(v.x, v.y);
};

float Vec::distance(Vec& position1, Vec& position2) {
	float x_value = (position1.x - position2.x) * (position1.x - position2.x);
	float y_value = (position1.y - position2.y) * (position1.y - position2.y);

	return sqrt(x_value + y_value);
}