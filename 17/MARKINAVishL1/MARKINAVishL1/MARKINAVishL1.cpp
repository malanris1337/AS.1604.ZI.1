// MARKINAVishL1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void code(vector<char> &k, vector<char> &t, string name_f)
{
	ofstream f(name_f);
	char n_simbol;
	int i = 0;
	for (int j = 0; j < t.size()-1; j++) {
		if (i > k.size()-1) {
			i = 0;
		}
		n_simbol = (k[i] + t[j]) % 255;
		f << n_simbol;
		cout << n_simbol;
		i++;
	}
	cout << endl;
	f.close();
}

void decode(vector<char> &k, vector<char> &t, string name_f)
{
	ofstream f(name_f);
	char n_simbol;
	int i = 0;
	for (int j = 0; j < t.size()-1; j++) {
		if (i > k.size()-1) {
			i = 0;
		}
		n_simbol = (t[j] - k[i]) % 255;
		f << n_simbol;
		cout << n_simbol;
		i++;
	}
	cout << endl;
	f.close();
}

int main(int argc, char* argv[])
{
	cout << "enddd" << endl;
	if ((argc > 1)&&(argc<=4)) {

		vector<char> key;
		vector<char> text;
		char t;

		cout << "KEY:" << endl;
		ifstream f_key(argv[1]);
		while (!f_key.eof())
		{
			t = f_key.get();
			cout << t;
			key.push_back(t);
		}
		cout << endl;
		f_key.close();

		cout << "TEXT:" << endl;
		ifstream f_text(argv[2]);
		while (!f_text.eof())
		{
			t = f_text.get();
			cout << t;
			text.push_back(t);
		}
		cout << endl;
		f_text.close();

		while (1) {
			cout << "1: Code" << endl;
			cout << "2: Decode" << endl;
			int p_menu;
			cin >> p_menu;
			switch (p_menu)
			{
			case 1: { cout << "CODE:" << endl;
				code(key, text,argv[3]);
				break;
			}
			case 2: { cout << "DECODE:" << endl;
				decode(key, text,argv[3]);
				break;
			}
			default: return 0;
			}
		}
	}
	cout << "end" << endl;
}



