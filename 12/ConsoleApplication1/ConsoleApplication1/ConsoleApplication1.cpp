// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void Coding(vector<char>& w, vector<char>& k);
void Decoding(vector<char>& w, vector<char>& k);

int main() 
{
	ifstream in("word.txt");
	vector<char> word;
	int x;
	while (!in.eof())
	{
		x = in.get();
		word.push_back(x);
	}
	cout << "Word: ";
	for (int i = 0; i < word.size(); i++)
		cout << word[i] << " ";

	ifstream fin("key.txt");
	vector<char> key;
	int y;
	while (!fin.eof())
	{
		y = fin.get();
		key.push_back(y);
	}
	cout << "Key: ";
	for (int i = 0; i < key.size(); i++)
		cout << key[i] << " ";

	void Coding(vector<char>& word, vector<char>& key);

	return 0;
}
	

void Coding(vector<char>& word, vector<char>& key)
{
	vector<char> v(word.size(), 0);
	cout << "Code: ";
	for (int i = 0; i < word.size(); i++)
	{
		v[i] = (word[i] + key[i]) % 256;
		cout << v[i] << " ";
	}
}
	
void Decoding(vector<char>& word, vector<char>& key)
{
	vector<char> v(word.size(), 0);
	cout << "Code: ";
	for (int i = 0; i < word.size(); i++)
	{
		v[i] = (word[i] + key[i]) % 256;
		cout << v[i] << " ";
	}
}


