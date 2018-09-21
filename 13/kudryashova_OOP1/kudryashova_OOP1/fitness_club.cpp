#include "stdafx.h"
#include "fitness_club.h"
#include "client.h"

fitness_club::fitness_club()
{
}


fitness_club::~fitness_club()
{
	clear();
}


void fitness_club::write()
{
	ofstream out("file.dat");
	out << fc_clients.size() << endl;
	for (auto&pClient : fc_clients)
	{
		pClient->write(out);
	}
}


void fitness_club::add(client* pClient)
{
	pClient->read();
	fc_clients.push_back(pClient);
}


void fitness_club::read()
{
	ifstream  in("file.txt");
	int n;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		client* pClient = new client;
		pClient->read(in);
		fc_clients.push_back(pClient);
	}
}


void fitness_club::print()
{
	for (auto&pClient : fc_clients)
	{
		pClient->write();
	}
}


void fitness_club::clear()
{
	for (auto&pClient : fc_clients)
	{
		delete pClient;
	}
	fc_clients.clear();
}
