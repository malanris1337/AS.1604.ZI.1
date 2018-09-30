#include "pch.h"
#include "cars.h"
#include "carshowroom.h"


carshowroom::carshowroom()
{
}


carshowroom::~carshowroom()
{
	clear();
}

void carshowroom::write()
{
	ofstream out("file.dat");
	out << cshroom_car.size() << endl;
	for (auto&pCars : cshroom_car)
	{
		pCars->write(out);
	}
}


void carshowroom::add(cars* pCars)
{
	pCars->read();
	cshroom_car.push_back(pCars);
}


void carshowroom::read()
{
	ifstream  in("file.dat");
	int n;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		cars* pCars = new cars;
		pCars->read(in);
		cshroom_car.push_back(pCars);
	}
}

void carshowroom::print()
{
	for (auto&pCars : cshroom_car)
	{
		pCars->write();
	}
}

void carshowroom::clear()
{
	for (auto &pCars : cshroom_car)
	{
		delete pCars;
	}
	cshroom_car.clear();
}
