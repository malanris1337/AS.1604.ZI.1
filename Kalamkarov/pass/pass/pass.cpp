// pass.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

using namespace std;

char inc(char key, char sym)
{
	return (key + sym) % 256;
}

char dec(char key, char sym)
{
	if (sym >= key)
		return sym - key;
	else
		return sym + 256 - key;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");


	if (argc < 2)
	{
		cout << "ошибка входных данных!" << endl;
		return 0;
	}

	
	ifstream fKey(argv[1]), fText(argv[2]);
	if ((!fKey.is_open()) || (!fText.is_open()))
	{
		cout << "ОШИБКА!" << endl;
		return 0;
	}

	ofstream Sinc("first.txt");
	ofstream Sdec("second.txt");

	// Считывание из потока в вектор
	vector<char> vKey((istreambuf_iterator<char>(fKey)), istreambuf_iterator<char>());

	vector<char>::iterator it = vKey.begin();
	while (1)
	{
		char sym;
		fText.get(sym);
		if (fText.eof()) break; // Провенрка идёт только после выхода за пределы

		char cEnc = inc(*it, sym);
		Sinc << cEnc;

		char cDec = dec(*it, cEnc);
		Sdec << cDec;

		it++;
		if (it == vKey.end())
			it = vKey.begin();
	}
	cout << "Процесс кодировки выполнен" << endl;
	return 0;
}
