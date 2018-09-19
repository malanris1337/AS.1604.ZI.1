// Tsimbalist_lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int menu()
{
	cout << "1:shifrovanie" << endl;
	cout << "2:deshifrovanie" << endl;
	cout << "0:exit" << endl;
	int k;
	cin >> k;
	return k;
}

void tsim(char * mas[]) 
{
	ifstream fin(mas[1]);
    ifstream win(mas[2]);
	ofstream fout(mas[3]);
	string st;
	win >> st;
	int l = st.length();
	char ch;
	ch = fin.get();
	int i = 0;
	while (!fin.eof())
	{
		i++;
		char p;
		int c = (int)ch;
		int k = (int)st[i];
		p = (char) ( (c + k) % 256);
		fout << p;
		if (i == l) i = 0;
		ch = fin.get();
	}
	fin.close();
	win.close();
	fout.close();
}

void netsim( char * mas[])
{
	ifstream fin(mas[3]);
	ifstream win(mas[2]);
	ofstream fout(mas[4]);
	string st ;
	win >> st;
	int l = st.length();
	char ch;
	ch = fin.get();
	int i = 0;
	while (!fin.eof())
	{
		i++;
		char p;
		int c = (int)ch;
		int k = (int)st[i];
		p = (char)((c - k + 256) % 256);
		fout << p;
		if (i == l) i = 0;
		ch = fin.get();
	}
	fin.close();
	win.close();
	fout.close();
}
int main(int argc, char* argv[])
{
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			tsim( argv);
			break;
		}
		case 2:
		{
			netsim( argv);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
    return 0;
}

