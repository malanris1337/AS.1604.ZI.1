#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void coding(char* argv1, char* argv2, char* argv3)
{
	ofstream outfile;
	outfile.open(argv3);
	string key;
	ifstream text, fkey;
	text.open(argv1);
	char number;
	int position = 0;
	fkey.open(argv2);
	fkey >> key;
	int lPass = key.size(); 
	if (!text.is_open())
	{
		cerr << "not open" << endl;
		exit(1);
	}
	while (!text.eof())
	{
		number = text.get();
		if (text.eof())  break;
		char d = char(int(number) + int(key[position]));
		position++;
		if (position == lPass) position = 0;
		outfile << d;

	}
	text.close();
	fkey.close();
	outfile.close();
}



void decoding(char* argv2, char* argv3, char* argv4)
{
	ofstream outffile;
	outffile.open(argv4);
	string key;
	ifstream ttext,ffkey;
	ttext.open(argv3);
	char number;
	int position = 0;
	ffkey.open(argv2);
	ffkey >> key;

	int lPass = key.size();
	if (!ttext.is_open())
	{
		cerr << "not open" << endl;
		exit(1);
	}

	while (!ttext.eof())
	{
		number = ttext.get();
		if (ttext.eof())  break;
		char d = char(int(number) - int(key[position]));
		position++;
		if (position == lPass) position = 0;
		outffile << d;
	}

	ttext.close();
	ffkey.close();
	outffile.close();
}

int ChooseAction()
{
	cout << "Меню:\n0: Идём на выход;\n1: Шифруем;\n2: Расшифруем;\n";
	int action;
	cout << "Выберете опцию:";
	cin >> action;
	return action;
}

int main(int argc, char *argv[])
{
	setlocale(0, "RUS");
	int choose;
	do
	{
		choose = ChooseAction();
		switch (choose)
		{
		case 1:
		{ 
		coding(argv[1], argv[2], argv[3]);
		break;
		}
		case 2:{
		  
		decoding(argv[2], argv[3], argv[4]);
		break;
		}
		}
	} while (choose != 0);

	return 0;
}
