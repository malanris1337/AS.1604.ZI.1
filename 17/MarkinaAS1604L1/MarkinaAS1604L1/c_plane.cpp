#include "stdafx.h"
#include "c_plane.h"


c_plane::c_plane()
{
}


c_plane::~c_plane()
{
}


void c_plane::AddPlane()
{	cout << "Enter the number of the plane" << endl;
	cin >> p_number;
	cout << "Enter the brand of the plane" << endl;
	cin >> p_brand;
	cout << "Enter the age of the plane" << endl;
	cin >> p_age;
	cout << "Enter the class of the plane" << endl;
	cin >> p_cl;
	cout << "Enter the manufacturer country of the plane" << endl;
	cin >> p_country_build;
	cout << "Enter the volume of the tank of the plane" << endl;
	cin >> p_tank;
	cout << "Enter the maximum capacity of the plane" << endl;
	cin >> p_size;

	cout << "Success!" << endl;
	cout << endl;
}

void c_plane::PrintPlane()
{	cout << "Number:  "<<p_number <<endl;
	cout << "Brand:  " << p_brand << endl;
	cout << "Age:  " << p_age << endl;
	cout << "Class:  " << p_cl << endl;
	cout << "Volume of tank:  " << p_tank << endl;
	cout << "Maximum capacity:  " << p_size << endl;
	cout << endl;
}


