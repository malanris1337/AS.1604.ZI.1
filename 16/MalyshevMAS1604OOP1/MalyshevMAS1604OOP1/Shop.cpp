#include "stdafx.h"
#include "Shop.h"


Shop::Shop()
{
}


Shop::~Shop()
{
}


void Shop::write_to_file()
{
	cout << "Enter the name of the file" << endl;
	string fl_name;
	cin >> fl_name;
	ofstream fout(fl_name);
	if (fout.is_open())
	{
		fout << sh_store.size() << endl;
		for (auto &c : sh_store)
		{
			c->write(fout);
		}
		cout << "Successfully" << endl;
	}
	else
		cout << "Error opening the file!" << endl;
	cout << endl;
}


void Shop::add_product(Product* pr)
{
	pr -> read();
	sh_store.push_back(pr);
	cout << "Product successfully added" << endl;
	cout << endl;
}


void Shop::read_from_file()
{
	cout << "Enter the name of the file" << endl;
	string fl_name;
	cin >> fl_name;
	ifstream  fin(fl_name);
	if (fin.is_open())
	{
		int n;
		fin >> n;
		for (int i = 0; i < n; ++i)
		{
			Product* pr = new Product;
			pr->read(fin);
			sh_store.push_back(pr);
		}
		cout << "Successfully" << endl;
	}
	else
		cout << "Error opening the file!" << endl;
	cout << endl;
}


void Shop::print_out_all()
{
	for (auto &c : sh_store)
	{
		c -> write();
	}
	cout << endl;
}


void Shop::clear()
{
	for (auto &c : sh_store)
	{
		delete c;
	}
	sh_store.clear();
	cout << "Successfully" << endl;
	cout << endl;
}