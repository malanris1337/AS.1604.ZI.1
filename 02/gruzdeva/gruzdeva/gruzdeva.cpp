// gruzdeva.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string>

using namespace std;

char code(char sym, char key)
{
	return (key + sym) % 256;
}

char decode(char sym, char key)
{
	if (sym >= key)
		return sym - key;
	else
		return sym + 256 - key;
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 3)
	{
		cout << "Не хватает входных аргументов" << endl;
		return 0;
	}

	string wordName = argv[1];
	string keyName = argv[2];

	ifstream fKey(keyName);
	ifstream fWord(wordName);
	ofstream fOut1("out1.txt");
	ofstream fOut2("out2.txt");

	vector<char> vKey((istreambuf_iterator<char>(fKey)), istreambuf_iterator<char>());
	string sRes = "";

	vector<char>::iterator itKey = vKey.begin();
	while (true)
	{
		char cWord;
		fWord.get(cWord);

		if (fWord.eof() == true)
			break;

		char cKey = *itKey;
		char res = code(cWord, cKey);

		fOut1 << res;
		sRes = sRes + res;

		itKey++;
		if (itKey == vKey.end())
			itKey = vKey.begin();
	}

	//itKey = vKey.begin();
	//for (auto it = vRes.begin(); it != vRes.end(); it++)
	//{
	//	char res = decode(*it, *itKey);

	//	fOut2 <<res;

	//	itKey++;
	//	if (itKey == vKey.end())
	//		itKey = vKey.begin();
	//}
	int length = sRes.length();
	for (int i = 0;i < length;i++)
	{
		char res = decode(sRes[i], *itKey);

		fOut2 << res;

		itKey++;
		if (itKey == vKey.end())
			itKey = vKey.begin();
	}

}

