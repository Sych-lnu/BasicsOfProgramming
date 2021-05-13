#pragma once
#include<iostream>
using namespace std;

struct Point
{
	float X;
	float Y;
	Point(float x = 0, float y = 0);
	float len(Point point);
};