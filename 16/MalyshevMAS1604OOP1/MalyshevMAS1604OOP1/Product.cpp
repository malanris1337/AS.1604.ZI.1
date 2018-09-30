#include "stdafx.h"
#include "Product.h"


Product::Product()
{
}


Product::~Product()
{
}


void Product::read()
{
	cout << "Enter the name of the product" << endl;
	cin >> pr_name;
	cout << "Enter the price of the product" << endl;
	cin >> pr_price;
}


void Product::write()
{
	cout << "Name of the product: ";
	cout << pr_name << endl;
	cout << "Price of the product: ";
	cout << pr_price << endl;
}


void Product::read(ifstream& fin)
{
	fin >> pr_name;
	fin >> pr_price;
}


void Product::write(ofstream& fout)
{
	fout << pr_name << endl;
	fout << pr_price << endl;
}