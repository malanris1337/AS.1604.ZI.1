// ZaharovaV.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ostream> 
using namespace std;

vector< char>  text(string name) {
	char m;
	vector<char> v;
	ifstream file(name);
	if (file.is_open())
	{
		while (!file.eof())
		{
			m = file.get();
			v.push_back(m);
		}
		file.close();
	}
	else cout << "Не удается открыть файл";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] ;
	}
	return v;
}

vector<char>  coding(vector< char> text, vector<char> key, string name) {
	int k = text.size()-1;
	int n = key.size()-1;
	vector< char> sh;
	char l;
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		if (j >= n)
		{
			j = 0;
		}
		
		l = (text[i] + key[j]) % 255;
		sh.push_back(l);
		cout << l;
		j++;
		
	}
	ofstream fout;
	fout.open(name);
	for (int i = 0; i < sh.size(); i++) {
		fout << sh[i];
	}
	fout.close();
	cout << endl;
	return sh;
}

vector<char>  decoding(vector< char> text, vector<char> key,string name) {
	int k = text.size()-1;
	int n = key.size()-1;
	vector<char> insh;
	char l;
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		if (j >= n)
			j = 0;
			l = (text[i] - key[j]) % 255;
			insh.push_back(l);
			cout << l;
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


int main(int argc , char *argv[])
{
	vector<char> v1, v2;
	setlocale(LC_ALL, "Russian");

	v1=text(argv[1]);
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
			coding(v1, v2,argv[3]);
			break; }
		case 2: {
			decoding(v1, v2,argv[3]);
			break; }
		case 3: {
			return 0;
			break; }
		default: cout << "Введите цифру от 1 до 3" << endl;
		}
	}
}