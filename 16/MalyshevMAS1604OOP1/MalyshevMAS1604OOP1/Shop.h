#pragma once

#include "Product.h"

class Shop
{
public:
	Shop();
	virtual ~Shop();
	vector<Product*> sh_store;
	void write_to_file();
	void add_product(Product*);
	void read_from_file();
	void print_out_all();
	void clear();
};

