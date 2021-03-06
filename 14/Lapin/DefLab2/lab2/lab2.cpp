// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <vector>


using namespace std;
// Получить чар ключа
char getKey(char cSym, char cCode)
{
	if (cCode >= cSym)
		return cCode - cSym;
	else
		return cCode + 256 - cSym;
}

// Заполнить массив частотного анализа
void getABC(vector<char>& vect, int* abc)
{
	for (int i = 0; i < 256; i++)
		abc[i] = 0;
	for (auto sym : vect)
		abc[sym + 128] += 1;
}

// Раскодировать по чару ключа
char decode(char key, char sym)
{
	if (sym >= key)
		return sym - key;
	else
		return sym + 256 - key;
}

// Поиск самого популярного символа
char mostPopular(int* abc)
{
	char popChar;
	int max = -1;
	for (int i = 0; i < 256; i++) 
		if (abc[i] > max) 
		{
			popChar = i - 128;
			max = abc[i];
		}
	return popChar;
}

// Сравнение на "ПОХОЖЕСТЬ" 2 массивов
double arrCompare(int* a1, int* a2)
{
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 256; i++)
	{
		sum1 += a1[i];
		sum2 += a2[i];
	}
	double res = 0;
	for (int i = 0; i < 256; i++)
	{
		double h1 = (double)a1[i] / sum1;
		double h2 = (double)a2[i] / sum2;
		res += abs(h1 - h2);
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	string nmCode;
	string nmTextModel;
	while (true)
	{
		int ans;

		cout << "Имя файла закодированного текста (без пробелов): " << endl;
		cin >> nmCode;
		cout << "Имя файла эталонного текста (без пробелов): " << endl;
		cin >> nmTextModel;
	
		ifstream finCode (nmCode);
		ifstream finModel(nmTextModel);
	
		if ((!finCode.is_open()) || (!finModel.is_open()))
		{
			cout << "Файл не может быть открыт!\n";
			return 0;
		}

		cout << "Считывание файлов..." << endl;
		vector<char> vModel((istreambuf_iterator<char>(finModel)), istreambuf_iterator<char>());
		vector<char> vCode ((istreambuf_iterator<char>(finCode )), istreambuf_iterator<char>()); // ПРОБЛЕМА! Не читает полностью!
		
		cout << "Диапазон длины подбираемого ключа: (через пробел):" << endl;
		int left, right;
		cin >> left; cin >> right;

		// Стат данные для эталона
		int aABCmodel[256];
		getABC(vModel,aABCmodel);
		char cPopModel = mostPopular(aABCmodel);
		
		int guessLen;
		double difMin = 10E20;
		vector <char> vDemoDecode;
		string sDemoKey;

		// Анализ ключа по каждой длине
		////////////////////////////////////////////////////////////////////
		for (int len = left; len <= right; len++)
		{
			cout << "Анализ "<<len<<"-значного ключа..."<< endl;
			vector < vector<char> > vCodeParts(len);
			
			// Разбитие вектора на части по длине ключа
			vector<char>::iterator it = vCode.begin();
			while (it != vCode.end()) 
			{
				for (auto& vPart : vCodeParts)
					if (it != vCode.end())
					{
						vPart.push_back(*it);
						it++;
					}
						
			}
			
			// Проанализировав все кратные части текста, узнаем все чары ключа 
			string sKey;
			vector<char> vDecode;
			for (auto vCharKey : vCodeParts)
			{
				int aABCcode[256];
				getABC(vCharKey,aABCcode);
				char cPopCode = mostPopular(aABCcode);
				char cKey = getKey(cPopModel, cPopCode);
				sKey += cKey;
			}

			// Декодируем текст под этот ключ
			cout << "Ключ: \"" << sKey<<"\"" << endl;
			int pos = 0;
			for (auto it : vCode)
			{
				char cDecode;
				cDecode = decode(sKey[pos], it);
				vDecode.push_back(cDecode);
				pos++;
				if (pos == len)
					pos = 0;
			}
			
			// Сравниваем отличие декодирование данного текста от эталонного по статистике букв
			int aABCdecode[256];
			getABC(vDecode, aABCdecode);
			double dif = arrCompare(aABCmodel, aABCdecode);
			// Если этот вариант ближе, запоминаем его
			if (dif < difMin)
			{
				difMin = dif;
				guessLen = len;
				sDemoKey = sKey;
				vDemoDecode = vDecode;
			}
	
			cout << "Коэффициент различия: " << dif << endl << endl;
		}
		////////////////////////////////////////////////////////////////////

		// Вывод результата
		cout << "===================================" << endl;
		cout << "Часть предполагаемого текста {" << endl;
		int count = 0;
		for (auto c : vDemoDecode)
		{
			if (count == 100)
				break;
			count++;
			cout << c;
		}
		cout << "}" << endl << endl;
		cout << "Предполагаемый ключ: \"" << sDemoKey << "\"" << endl << endl;
		
		// Сохранение в файл
		string sOutName;
		cout << "Имя файла для сохранения: (без пробелов)" << endl;
		cin >> sOutName;
		ofstream fout(sOutName);
		for (auto c : vDemoDecode)
			fout << c;
		cout << "Файл успешно сохранён." << endl << endl;

		cout << "Расшифровать другой файл? (1/0)" << endl;
		cin >> ans;
		if (!ans)
			return 0;

	}

}

