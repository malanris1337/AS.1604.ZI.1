#pragma once
class tsim_player
{
public:

	tsim_player();
	virtual ~tsim_player();
	string name;
	int age;
	void read();
	void write();
	void read(ifstream& in);
	void write(ofstream& out);
};

