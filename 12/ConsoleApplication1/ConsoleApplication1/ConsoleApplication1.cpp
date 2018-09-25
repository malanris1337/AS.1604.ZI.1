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



	Coding(word, key, argv[3]);
	Decoding(argv[3], key, argv[4]);
	


	return 0;
}
	

void Coding(vector<char> word, vector<char> key, char* text)
{
	ofstream out;
	out.open(text);
	while (out)
	{
		for (int i = 0; i < word.size(); i++)
		{
			char v;
			v = (word[i] + key[i]) % 255;
			out << v;
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
	for (int i = 0; i < word.size(); i++)
	{
		v = (word[i] - key[i]) % 255;
		out << v;
	}
	out.close();
}


