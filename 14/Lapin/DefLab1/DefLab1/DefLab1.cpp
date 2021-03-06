// DefLab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
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

	string nmKey, nmText;
	cout << "Имя файла ключа:" << endl;
	cin >> nmKey;
	cout << "Имя файла текста:" << endl;
	cin >> nmText;

	ifstream finKey(nmKey), finText(nmText);

	if ((!finKey.is_open()) || (!finText.is_open()))
	{
		cout << "Файл не может быть открыт!\n";
		return 0;
	}

	ofstream StrmEnc("encode.txt"), StrmDec("decode.txt");

	
	vector<char> vKey((istreambuf_iterator<char>(finKey)),istreambuf_iterator<char>());

	vector<char>::iterator it = vKey.begin();	
	while (1)
	{

		char sym;
		finText.get(sym);

		if (finText.eof()) break; 

		char cEnc = Encode(*it,sym);
		StrmEnc << cEnc;

		char cDec = Decode(*it,cEnc);
		StrmDec << cDec;

		it++;
		if (it == vKey.end())
			it = vKey.begin();
	}
	return 0;
}
