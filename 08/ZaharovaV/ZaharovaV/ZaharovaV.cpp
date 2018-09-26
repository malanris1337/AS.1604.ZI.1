// ZaharovaV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream> 
using namespace std;

vector<unsigned char>  text(string name) {
	char m;
	vector<unsigned char> v;
	ifstream file(name);
	if (file.is_open())
	{
		m = file.get();
		while (!file.eof())
		{
			v.push_back(m);
			m = file.get();
		}
		file.close();
	}
	else cout << "Не удается открыть файл";
	
	return v;
}

vector<unsigned char>  coding(vector<unsigned char> text, vector<unsigned char> key, string name) {
	int k = text.size() ;
	int n = key.size() ;
	vector<unsigned char> sh;
	char l;
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		if (j >= n)
		{
			j = 0;
		}

		l = (text[i] + key[j]) % 256;
		sh.push_back(l);
		j++;

	}
	ofstream fout;
	fout.open(name);
	for (int i = 0; i < sh.size(); i++) {
		fout << sh[i];
	}
	fout.close();
	return sh;
}

vector<unsigned char>  decoding(vector<unsigned char> text, vector<unsigned char> key, string name) {
	int k = text.size();
	int n = key.size();
	vector<unsigned char> insh;
	char l;
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		if (j >= n)
			j = 0;
		l = (text[i] - key[j]) % 256;
		insh.push_back(l);
		j++;


	}
	ofstream fout;
	fout.open(name);
	for (int i = 0; i < insh.size(); i++) {
		fout << insh[i];
	}
	fout.close();
	return insh;
}


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 4) {
		cout << "Не хватает аргументов" << endl;
		return 0;
	}
	vector<unsigned char> v1, v2;
	v1 = text(argv[1]);
	v2 = text(argv[2]);
	while (1) {
		cout << endl;
		cout << "1: Зашифровать " << endl;
		cout << "2: Расшифровать" << endl;
		cout << "3: Выйти из программы" << endl;
		int a;
		while (!(cin >> a))
		{
			cin.clear();
			cin.ignore();
			cout << "Неккоректный ввод. Попробуйте еще раз." << endl;
		}
		switch (a)
		{
		case 1: {
			coding(v1, v2, argv[3]);
			break; }
		case 2: {
			decoding(v1, v2, argv[3]);
			break; }
		case 3: {
			return 0;
			break; }
		default: cout << "Введите цифру от 1 до 3" << endl;
		}
	}
}
