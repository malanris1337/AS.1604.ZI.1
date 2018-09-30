
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void encode(vector<char> &k, vector<char> &t, char* argv1) //кодирование из out.txt в out2.txt
{
	ofstream f;
	f.open(argv1);
	char sym;
	int i = 0;
	for (int j = 0; j != t.size(); j++)
	{
		if (i > k.size() - 1)
		{
			i = 0;
		}
		sym = (k[i] + t[j]) % 255;
		f << sym;
		cout << sym;
		i++;
	}
	cout << endl;
	f.close();
}

void decode(vector<char> &k, char* argv1, char* argv2) //декодирование из out.txt в out2.txt
{
	vector<char> text;
	char t;
	ifstream f_text(argv1);
	while (!f_text.eof())
	{
		t = f_text.get();
		text.push_back(t);
	}
	text.erase(text.end() - 1);

	ofstream f;
	f.open(argv2);
	char sym;
	int i = 0;
	for (int j = 0; j != text.size(); j++)
	{
		if (i > k.size() - 1)
		{
			i = 0;
		}
		sym = (text[j] - k[i]) % 255;
		f << sym;
		cout << sym;
		i++;
	}
	cout << endl;
	f.close();
}

int main(int argc, char *argv[])
{
	vector<char> key;
	vector<char> text;
	char t;


	ifstream f_key;
	f_key.open(argv[1]);
	while (!f_key.eof())
	{
		t = f_key.get();
		key.push_back(t);
	}
	key.erase(key.end() - 1);
	cout << "key: ";
	for (int i = 0; i != key.size(); i++)
	{
		cout << key[i];
	}
	cout << "\n";

	f_key.close();


	ifstream f_text(argv[2]);
	while (!f_text.eof())
	{
		t = f_text.get();
		text.push_back(t);
	}
	text.erase(text.end() - 1);
	cout << "TEXT: ";
	for (int i = 0; i != text.size(); i++)
	{
		cout << text[i];
	}
	cout << "\n";
	f_text.close();

	while (1)
	{
		cout << "1: encode\n";
		cout << "2: decode\n";
		int menu;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "encode: ";
			encode(key, text, argv[3]);
			break;
		}
		case 2:
		{
			cout << "decode: ";
			decode(key, argv[3], argv[4]);
			break;
		}
		default:
			cout << "Error! Input correct number!\n";
		}
	}
}
