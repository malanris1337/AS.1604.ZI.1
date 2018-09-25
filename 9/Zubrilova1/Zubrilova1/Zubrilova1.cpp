// Zubrilova1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include <string>
#include <fstream>
#include "string"
using namespace std;

void shifr(char*argv, char*argv2, char*argv3)
{
	char symb;
	string key;
	ofstream fout(argv3);
	ifstream fin, fan;
	fin.open(argv);
	int i = 0;
	fan.open(argv2);
	fan >> key;
	int l = key.length();
	symb = fin.get();
	while (!fin.eof())
	{

		int p = (int)symb;
		if (i > l)
			i = 1;
		int k = (int)key[i];
		int c = (p + k) % 256;
		fout << (char)c;
		i++;
		symb = fin.get();

	}
	fin.close();
	fan.close();
	fout.close();
	
}
void deshifr(char*argv2, char*argv3, char*argv4)
{
	char symb;                                
	string key;
	ofstream out(argv4);
	ifstream in, an;
	in.open(argv3);
	an.open(argv2);
	an >> key;
	int l = key.length();
	int i = 0;
	symb = in.get();
	while (!in.eof())
	{

		int p = (int)symb;
		if (i >  l)
			i = 1;
		int k = (int)key[i];
		int c = (p - k + 256) % 256;
		out << (char)c;
		i++;
		symb = in.get();
	}
	in.close();
	an.close();
	out.close();
}


int main(int argc, char*argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc != 4)
		cout << "Введено неверное количество файлов" << endl;
	int n;
	for (;;)
	{
		cout << "1.Зашифровать" << endl;
		cout << "2.Дешифровать" << endl;
		cout << "3.Выход" << endl;
		cout << "Выберите действие:" << endl;
		cin >> n;

		switch (n)
		{
		case 1:
		{
			
			shifr(argv[1],argv[2],argv[3]);
			break;
		}
		case 2:
		{
			
			deshifr(argv[2], argv[3], argv[4]);
			break;
		}
		case 3:
		{
			return 0;
			break;
		}

		default:
			cout << "Введен неверный пункт меню";
			break;		
		}
	}
	return 0;
}


