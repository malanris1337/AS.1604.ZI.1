// Sazonovlab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

template <typename T>
T Proverka(T bottom, T up)
{
	T y;
	while (!(cin >> y) || (y < bottom) || (y > up))
	{
		cout << "Ошибка! Повторите попытку" << endl;
		cin.clear();
		cin.ignore();
	}
	return y;
}

bool menu(bool &exit);
char Vizhener(char input, vector <char> &password, int mode, int t);


int main(int argc, char* argv[])
{
	setlocale(0, "RUS");
	bool exit = false;
	vector <char> key_vector;
	string key=argv[2];
	//int k = 0;
	while (!exit)
	{
		ifstream fopen;
		fopen.open(argv[1]);

		string in_file_name=argv[1];
		cout << "Введите имя файла, из которого надо считать: " << endl;
		fopen >> argv[1];

	

		while (!fopen.is_open())
		{
			cout << "Такого файла не существует!" << endl;
			cout << "Введите нзвание снова: " << endl;
			fopen >> argv[1];
			fopen.open(argv[1]);
		}
		cout << "Введите ключ: " << endl;
		fopen >> argv[2];
		const char* strdata = key.c_str();

		char c;
		for (int i = 0; i < int(key.size()); i++) {
			c = strdata[i];
			key_vector.push_back(c);
		}

		string out_file_name=argv[3];
		ofstream fout;
		fout.open(argv[3]);
		cout << "Введите название файла, в который надо записать: " << endl;
		fout << argv[3];

		

		char mode;
		cout << "0 - шифрование, 1 - дешифрование: " << endl;
		mode = Proverka('0', '1');

		char output;
		char  input;
		int t = 0; //current position in file

		while (!fout.eof()) {// выдтает истину если фаил пуст
			input = fopen.get();

			if (input != EOF) {
				output = Vizhener(input, key_vector, mode, t);

				fout << output;
				t++;
			}
		}

		fopen.close();
		fout.close();

		key_vector.clear();

		menu(exit);
		cin.ignore();
	}

	return 0;
}
bool menu(bool &exit)
{
	int i;
	char tr;
	do
	{
		cout << "0 - продолжить, 1 - выйти" << endl;
		cin >> tr;
		i = static_cast<int>(tr);
		if (i < '0' || i > '1')
		{
			cout << "неправильный номер" << endl;
		}
	} while (i < '0' || i > '1');
	switch (i)
	{
	case '0':exit = 0;
		break;
	case '1':exit = 1;
		break;
	}
	return exit;
}
char Vizhener(char input, vector <char> &password, int mode, int t)
{
	switch (mode)
	{
	case'0':
	{
		int size = t % (password.size());
		unsigned char p = static_cast<unsigned char>(password[size]);
		unsigned char res = ((int(input) + int(p)) % (256));
		return res;
		break;
	}
	case '1':
	{
		int size = t % (password.size());
		unsigned char p = static_cast<unsigned char>(password[size]);
		unsigned char res = ((int(input) - int(p) + 256) % (256));
		return res;
		break;
	}
	default:
		cout << "0 - шифрование, 1 - дешифрование" << endl;
		break;
	}
}