// DP_Simonov_Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//
//argv1 - key
//argv2 - text
//argv3 - code
//argv4 - decode
//

void code(vector<char> key, vector<char> text, char* c)
{
	ofstream fout;
	char s;

	fout.open(c);
	int i = 0;
	for (int j = 0; j < text.size(); j++)
	{
		if (i > key.size() - 1)
			i = 0;

		s = (key[i] + text[j]) % 255;
		fout << s;
		i++;
	}
	fout.close();
}

void decode(vector<char> key, char* b, char* c)
{
	ifstream fin;
	ofstream fout;
	char s;
	vector<char> text;

	fin.open(b);
	while (!fin.eof())
	{
		s = fin.get;
		text.push_back(s);
	}
	text.erase(text.end() - 1);
	fin.close();

	fout.open(c);
	int i = 0;
	for (int j = 0; j < text.size(); j++)
	{
		if (i > key.size() - 1)
			i = 0;

		s = (text[j] - key[i]) % 255;
		fout << s;
		i++;
	}
	fout.close();
}

int main(int argc, char *argv[])
{
	ifstream fin;
	char s;
	vector<char> key;
	vector<char> text;

	fin.open(argv[1]);
	while (!fin.eof())
	{
		s = fin.get;
		key.push_back(s);
	}
	key.erase(key.end() - 1);
	fin.close();

	fin.open(argv[2]);
	while (!fin.eof())
	{
		s = fin.get;
		text.push_back(s);
	}
	text.erase(text.end() - 1);
	fin.close();


	code(key, text, argv[3]);
	decode(key, argv[3], argv[4]);

	return 0;
}

