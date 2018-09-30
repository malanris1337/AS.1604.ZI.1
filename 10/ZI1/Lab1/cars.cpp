#include "cars.h"
#include "pch.h"
cars::cars()
{
}

cars::~cars()
{
}


void cars::read()
{
	cout << "Input car: " << endl;
	cin >> c_name;
	cout << "Input date of building: " << endl;
	cin >> c_date;
}


void cars::write()
{
	cout << "Car:";
	cout << c_name << endl;
	cout << "Build: ";
	cout << c_date << endl;
}


void cars::read(ifstream& in)
{
	in >> c_name;
	in >> c_date;
}


void cars::write(ofstream& out)
{
	out << c_name << endl;
	out << c_date << endl;
}
