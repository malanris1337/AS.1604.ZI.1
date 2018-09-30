#pragma once

class Product
{
public:
	Product();
	virtual ~Product();
	string pr_name;
	double pr_price;
	void read();
	void write();
	void read(ifstream& fin);
	void write(ofstream& fout);
};

