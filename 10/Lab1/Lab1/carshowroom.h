#pragma once
#include "pch.h"
#include "cars.h"
using namespace std;
class carshowroom
{
public:
	carshowroom();
	virtual ~carshowroom();
	vector<cars*> cshroom_car;
	void write();
	void add(cars*);
	void read();
	void print();
	void clear();
};