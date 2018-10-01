#pragma once
class tsim_team
{
public:
	vector<tsim_player*>tm_players;
	tsim_team();
	virtual ~tsim_team();
	void add(tsim_player* tpl);
	void read();
	void print();
	void write();
	void clear();
};

