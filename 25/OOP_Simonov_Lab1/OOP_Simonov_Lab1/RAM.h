#pragma once
#include "unit.h"

class RAM
{
public:
	RAM();
	virtual ~RAM();
	vector<unit* > units;
	void outputf();
	void input(unit*);
	void inputf();
	void output();
	void clear();
};

