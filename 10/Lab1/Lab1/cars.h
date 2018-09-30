#pragma once
#include "pch.h"
class cars
{
public:
	cars();
	virtual ~cars();
	string c_name;
	int c_date;
	void read();
	void write();
	void read(ifstream& in);
	void write(ofstream& out);
};