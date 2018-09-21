#pragma once
using namespace std;
class fitness_club
{
public:
	fitness_club();
	virtual ~fitness_club();
	vector<client* > fc_clients;
	void write();
	void add(client* );
	void read();
	void print();
	void clear();
};

