// MalyshevMAS1604ZLab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Encode(char* k, char* t)
{
	vector<char> key;
	vector<char> txt;

	ifstream fin;
	fin.open(k);
	while (!fin.eof())
	{
		char kk;
		fin >> kk;
		key.push_back(kk);
	}
	key.erase(key.end() - 1);
	fin.close();

	fin.open(t);
	while (!fin.eof())
	{
		char kk;
		fin >> kk;
		txt.push_back(kk);
	}
	txt.erase(txt.end() - 1);
	fin.close();

	ofstream fout;
	fout.open("output.txt");
	auto meta = key.begin();
	for (auto i = txt.begin(); i != txt.end(); i++)
	{
		if (meta == key.end())
		{
			meta = key.begin();
		}
		char kk = (*i + *meta) % 256;
		fout << kk;
		meta++;
	}
	fout.close();
}

void Decode(char* k)
{
	vector<char> key;
	vector<char> txt;

	ifstream fin;
	fin.open(k);
	while (!fin.eof())
	{
		char kk;
		fin >> kk;
		key.push_back(kk);
	}
	key.erase(key.end() - 1);
	fin.close();

	fin.open("output.txt");
	while (!fin.eof())
	{
		char kk;
		fin >> kk;
		txt.push_back(kk);
	}
	txt.erase(txt.end() - 1);
	fin.close();

	ofstream fout;
	fout.open("decoutput.txt");
	auto meta = key.begin();
	for (auto i = txt.begin(); i != txt.end(); i++)
	{
		if (meta == key.end())
		{
			meta = key.begin();
		}
		char kk = (*i - *meta) % 256;
		fout << kk;
		meta++;
	}
	fout.close();
}

int main(int argc, char* argv[])
{
	Encode(argv[1], argv[2]);
	Decode(argv[1]);
    return 0;
}

