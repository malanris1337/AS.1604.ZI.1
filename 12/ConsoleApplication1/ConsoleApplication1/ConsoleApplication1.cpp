// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void Coding(vector<char> w, vector<char> k, char* t);
void Decoding(char* w, vector<char> k, char* TEXT);

int main(int argc, char* argv[]) 
{
	vector<char> key;
	vector<char> word;

	ifstream in;
	in.open(argv[1]);

	while (!in.eof())
	{
		char x;
		x = in.get();
		word.push_back(x);
	}
	word.erase(word.end() - 1);
	in.close();

	
	in.open(argv[2]);
	
	while (!in.eof())
	{
		char y;
		y = in.get();
		key.push_back(y);
	}
	key.erase(key.end() - 1);
	in.close();

	while (1)
	{
		cout << "1 - Coding\n2- Decoding\n ";
		int index;
		cin >> index;
		switch (index)
		{
		case 1:
		{
				  Coding(word, key, argv[3]);
		}
		case 2:
		{
				  Decoding(argv[3], key, argv[4]);
		}
		deault: return 0;
		}

	}
	return 0;
}
	

void Coding(vector<char> word, vector<char> key, char* text)
{
	ofstream out;
	out.open(text);

	while (out)
	{
		int j = 0;
		char v;
		for (int i = 0; i < word.size(); i++)
		{
			if (j > key.size() - 1)

				j = 0;
			
			v = (word[i] + key[j]) % 256;
			out << v;

			j++;
		}
		out.close();
	}
	
}

	
void Decoding(char* text, vector<char> key, char* TEXT)
{

	ifstream in;
	ofstream out;
	char v;
	
	vector<char> word;
	in.open(text);
	while (!in.eof())
	{
		in >> v;
		word.push_back(v);
	}
	word.erase(word.end() - 1);
	out.close();

	out.open(TEXT);
	int j = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (j > key.size() - 1)

			int j = 0;

		v = (word[i] - key[j]) % 256;
		out << v;

		j++;
	}
	out.close();
}


