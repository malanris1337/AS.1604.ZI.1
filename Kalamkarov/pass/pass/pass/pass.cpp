// pass.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

using namespace std;

char Encode(char key, char sym)
{
	return (key + sym) % 256;
}

char Decode(char key, char sym)
{
	if (sym >= key)
		return sym - key;
	else
		return sym + 256 - key;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream finKey("key.txt"), finText("text.txt");
	if ((!finKey.is_open()) || (!finText.is_open()))
	{
		cout << "Файл не может быть открыт!\n";
		return 0;
	}

	ofstream StrmEnc("doit.txt");
	ofstream StrmDec("goback.txt");

	// Считывание из потока в вектор
	vector<char> vKey((istreambuf_iterator<char>(finKey)), istreambuf_iterator<char>());

	vector<char>::iterator it = vKey.begin();
	while (1)
	{
		char sym;
		finText.get(sym);
		if (finText.eof()) break; // Провенрка идёт только после выхода за пределы

		char cEnc = Encode(*it, sym);
		StrmEnc << cEnc;

		char cDec = Decode(*it, cEnc);
		StrmDec << cDec;

		it++;
		if (it == vKey.end())
			it = vKey.begin();
	}
	cout << "Процесс кодировки выполнен" << endl;
	return 0;
}
