// shifr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int menu()
{
	int i;
	cout << "Menu\n 1:Shifr\n 2:Deshifr\n 0:Exit" << endl;
	cin>> i;
	return i;
}

void deshifr(int n, char* mas[])
{
	fstream fin(mas[3]);
	char ch, c;
	string s;
	fstream in(mas[2]);
	in >> s;
	int l = s.length();
	char k;
	ofstream fout(mas[4]);
	ch = fin.get();
	int i = 1;
	while (!fin.eof())
	{
		
			k = s[i];
			int p;
			p = int(ch - k+256) % 256;
			c = (char)p;
			fout << c;
			ch = fin.get();
			i++;
			if (i == l) i = 1;
	}
	fout.close();
	fin.close();
	in.close();
}

void shifr(int n, char* mas[])
{
	fstream fin(mas[1]);
	char ch, c;
	string s;
	fstream in(mas[2]);
	in >> s;
	int l = s.length();
	char k;
	ofstream fout(mas[3]);
	ch = fin.get();
	int i = 1;
	while (!fin.eof())
	{
			
				k = s[i];
				int p;
				p = int(ch + k) % 256;
				c = (char)p;
				fout << c;
				ch = fin.get();				
				i++;
				if (i == l) i = 1;
	}
	fout.close();
	fin.close();
	in.close();
}

void start(int n, char* mas[])
{
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			shifr(n, mas);
			break;
		}
		case 2:
		{
			deshifr(n, mas);
			break;
		}
		default:
		{
			return;
		}
		}
	}
}

int main(int argc, char* argv[])
{
	start(argc, argv);
    return 0;
}
