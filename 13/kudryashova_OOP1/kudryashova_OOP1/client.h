#pragma once
#include <string>


class client
{
public:
	client();
	virtual ~client();
	string c_name;
	int c_date;
	void read();
	void write();
	void read(ifstream& in);
	void write(ofstream& out);
};

