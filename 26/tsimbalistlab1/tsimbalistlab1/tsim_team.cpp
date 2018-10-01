#include "stdafx.h"
#include "tsim_player.h"
#include "tsim_team.h"


tsim_team::tsim_team()
{
}


tsim_team::~tsim_team()
{
}


void tsim_team::add(tsim_player* tpl)
{
	tpl->read();
	tm_players.push_back(tpl);
}


void tsim_team::read()
{
	ifstream in("file.dat");
	int n;
	in >> n;
	for (int i = 0; i < n; i++) 
	{
		tsim_player* tpl = new tsim_player;
		tpl->read(in);
		tm_players.push_back(tpl);
	}
}


void tsim_team::print()
{
	for (auto&tpl : tm_players)
	{
		tpl->write();
	}
}


void tsim_team::write()
{
	ofstream out("file.dat");
	out << tm_players.size() << endl;
	for (auto&tpl : tm_players)
	{
		tpl->write(out);
	}
}


void tsim_team::clear()
{
	for (auto&tpl : tm_players)
	{
		delete tpl ;
	}
	tm_players.clear();
}
