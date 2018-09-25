#include "stdafx.h"
#include "client.h"


client::client()
{
	
}


client::~client()
{
}


void client::read()
{
	cout << "Input name of client" << endl;
	cin >> c_name;
	cout << "Input birthday DDMMYYYY" << endl;
	cin >> c_date;
}


void client::write()
{
	cout << "Name of client:";
	cout<< c_name<<endl;
	cout << "Birthday: " ;
	cout << c_date << endl;
}


void client::read(ifstream& in)
{
	in >> c_name;
	in >> c_date;
}


void client::write(ofstream& out)
{
	out << c_name << endl;
	out << c_date << endl;
}
