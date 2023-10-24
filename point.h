#pragma once
struct point{
	float x;
	float y;
	point(float _x, float _y):x(_x), y(_y){}
	point(const point& other) :x(other.x), y(other.y){}
};

