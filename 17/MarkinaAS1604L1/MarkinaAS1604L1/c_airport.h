#pragma once
#include "stdafx.h"
#include "c_plane.h"

class c_airport
{
	vector<c_plane> planes;
	string a_name = "null";
	int a_plane_count = planes.size();
	string a_country = "null";
	string a_city = "null";
	string data_build = "dd.mm.yyyy";

public:
	c_airport();
	~c_airport();
	void AddAirport();
    void PrintAirport();
};

