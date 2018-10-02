#include "stdafx.h"
#include "functions.h"

char code(char key, char word)
{
	return (key + word) % 256;
}

char decode(char key, char word)
{
	if (word >= key)
		return word - key;
	else
		return word + 256 - key;
}

int f(string text1, string text2, string key)
{
	ifstream TEXT1(text1), KEY(key);
	if (!TEXT1.is_open())
	{
		cout << "Ошибка в открытии файла " << text1 << endl;
		return 0;
	}

	if (!KEY.is_open())
	{
		cout << "Ошибка в открытии файла " << key << endl;
		return 0;
	}

	if (TEXT1.peek() == EOF)
	{
		cout << "Файл " << text1 << " пуст" << endl;
		return 0;
	}

	if (KEY.is_open() == EOF)
	{
		cout << "Файл " << key << " пуст" << endl;
		return 0;
	}

	ofstream out_encoded(text2), TEXT3("3text.txt");
	vector<char> vector_key;

	while (true)
	{
		char s;
		KEY.get(s);
		if (KEY.eof())
			break;
		vector_key.push_back(s);
	}

	vector<char>::iterator i = vector_key.begin();
	while (true)
	{
		char s;
		TEXT1.get(s);
		if (TEXT1.eof())
			break;
		char inTEXT2 = code(*i, s);
		out_encoded << inTEXT2;

		i++;
		if (i == vector_key.end())
			i = vector_key.begin();
	}
	i = vector_key.begin();
	out_encoded.close();


	ifstream in_encoded(text2);
	while (true)
	{
		char s;
		in_encoded.get(s);
		if (in_encoded.eof())
			break;
		char inTEXT3 = decode(*i, s);
		TEXT3 << inTEXT3;

		i++;
		if (i == vector_key.end())
			i = vector_key.begin();
	}
}