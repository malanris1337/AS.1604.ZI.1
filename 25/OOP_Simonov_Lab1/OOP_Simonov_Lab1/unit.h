#pragma once
#include "string"
class unit
{
public:
	unit();
	virtual ~unit();
	string r_type;
	int r_size;
	void input();
	void output();
	void inputf(ifstream &fin);
	void outputf(ofstream &fout);
};
