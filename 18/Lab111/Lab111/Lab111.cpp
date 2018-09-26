// Lab111.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

using namespace std;

int check(int t)
{
	
	while ((t<1) || (t>2))
	{
		cin.clear();
		cin.ignore();
		cin >> t;
		cout << "input correct number" << endl;
	}
	return t;
}

char encryption(char key, char letter)
{
	return (key + letter) % 256;
}

char decoding(char key, char letter)
{
	if (letter >= key)
	{
		return (letter - key) % 256;
	}
	else
		return (letter - key + 256) % 256;
}


int main(int argc, char* argv[])
{
	cout << "choose following positions:" << endl;

	cout << "choose your files(1)" << endl;

	cout << "choose actual files(2)" << endl;
	int k;
	cin >> k;
	int p;
	p=check(k);

	switch (p)
	{
	case 1:
	{
		/*cout << "Input keyfilename" << endl;
		string keyfilename;
		cin >> keyfilename;
		cout << "Input letterfilename" << endl;
		string letterfilename;
		cin >> letterfilename;*/


		ifstream finkey(argv[1]), finletter(argv[2]);
		if ((!finkey.is_open()) || (!finletter.is_open()))
		{
			cout << "file is not open" << endl;
			return 0;
		}
		ofstream StrmEnc("encrypted.txt");
		ofstream StrmDec("decoded.txt");
		vector<char> vKey((istreambuf_iterator<char>(finkey)), istreambuf_iterator<char>());

		vector<char>::iterator it = vKey.begin();

		while (1)
		{
			char letter;
			finletter.get(letter);
			if (finletter.eof()) break;

			char cEnc = encryption(*it, letter);
			StrmEnc << cEnc;

			char cDec = decoding(*it, cEnc);
			StrmDec << cDec;

			it++;
			if (it == vKey.end())
				it = vKey.begin();
		}
		return 0;
	}
	case 2:

	{



		ifstream finkey("key.txt"), finletter("text.txt");
		if ((!finkey.is_open()) || (!finletter.is_open()))
		{
			cout << "file is not open" << endl;
			return 0;
		}
		ofstream StrmEnc("encrypted.txt");
		ofstream StrmDec("decoded.txt");
		vector<char> vKey((istreambuf_iterator<char>(finkey)), istreambuf_iterator<char>());

		vector<char>::iterator it = vKey.begin();

		while (1)
		{
			char letter;
			finletter.get(letter);
			if (finletter.eof()) break;

			char cEnc = encryption(*it, letter);
			StrmEnc << cEnc;

			char cDec = decoding(*it, cEnc);
			StrmDec << cDec;

			it++;
			if (it == vKey.end())
				it = vKey.begin();
		}
		return 0;


	}

	}
}