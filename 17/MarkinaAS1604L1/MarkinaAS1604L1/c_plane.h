#pragma once
#include"stdafx.h"
class c_plane
{
	int p_number = 0;
	string p_brand = "null";
	int p_age = 0;
	string p_country_build = "null";
	int p_tank = 0;
	int p_size= 0;
	char p_cl = 0;

public:
	c_plane();
	~c_plane();
	void AddPlane();
	void PrintPlane();
};

