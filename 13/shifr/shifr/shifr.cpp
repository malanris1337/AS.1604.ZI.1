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
	char ch, c;
	string s;
	fstream in(mas[2]);
	char k;
	int l = s.length();
	in >> s;
	fstream pin(mas[3]);
	ofstream gout("deshifr.txt");
	ch = pin.get();
	int p;
	while ((ch) != EOF)
	{
		for (int i = 1; i <= l; i++)
		{
			k = s[i];
			p = int(ch - k + 256) % 256;
			c = (char)p;
			cout << c;
			gout << c;
			ch = pin.get();
		}
	}
	gout.close();
	pin.close();
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
	while (ch != EOF)
	{
			for (int i = 1; i <= l; i++)
			{
				k = s[i];
				int p;
				p = int(ch + k) % 256;
				c = (char)p;
				cout << c;
				fout << c;
				ch = fin.get();				
			}
	}
	fout.close();
	fin.close();
	in.close();
}

void start(int n, char* mas[])
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

int main(int argc, char* argv[])
{
	start(argc, argv);
    return 0;
}
