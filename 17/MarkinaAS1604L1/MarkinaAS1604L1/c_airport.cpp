#include "stdafx.h"
#include "c_airport.h"


c_airport::c_airport()
{
}


c_airport::~c_airport()
{
}


void c_airport::AddAirport()
{
	cout << "Enter the name (max 3 simbols) of airport" << endl;
	cin >> a_name;
	cout << "Enter the country" << endl;
	cin >> a_country;
	cout << "Enter the city" << endl;
	cin >> a_city;
	cout << "Enter the data of build of airport" << endl;
	cin >> data_build;
	cout << "Success!" << endl;
	cout << endl;
}


 void c_airport::PrintAirport()
{
	cout << "Name: " <<a_name<< endl;
	cout << "Country: " <<a_country<< endl;
	cout << "City: " <<a_city<< endl;
	cout << "Data of build: " <<data_build<< endl;
	cout << "Count of planes: " << a_plane_count << endl;
	for (int i = 0; i < planes.size(); i++) {
		planes[i].PrintPlane();
	}
	cout << endl;
}
