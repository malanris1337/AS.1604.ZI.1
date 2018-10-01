#include "stdafx.h"
#include "tsim_player.h"


tsim_player::tsim_player()
	: age(0)
{
}


tsim_player::~tsim_player()
{
}


void tsim_player::read()
{
	cout << "Input name of player" << endl;
	cin >> name;
	cout << "Input age of player" << endl;
	cin >> age;
}


void tsim_player::write()
{
	cout << "Name of player: " ;
	cout << name << endl;
	cout << "Age of player: " ;
	cout << age << endl;
}



void tsim_player::read(ifstream& in)
{
	in >> name;

	in >> age;
}


void tsim_player::write(ofstream& out)
{
	out << name << endl;
	out << age << endl;
}
