// OOP_Simonov_Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "OOP_Simonov_Lab1.h"
#include "unit.h"
#include "RAM.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

using namespace std;

int menu()
{
	int i;
	cout << "1: Добавить" << endl;
	cout << "2: Вывести" << endl;
	cout << "3: Сохранитиь в файл" << endl;
	cout << "4: Загрузить из файла" << endl;
	cout << "5: Очистить" << endl;
	cout << "0: Выйти" << endl;
	cin >> i;
	cout << endl;
	return i;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	RAM r;

	ofstream fout("input.txt");
	fout << "(Всего единиц)" << endl << "(Тип ОЗУ)" << endl << "(Объём ОЗУ)" << endl;
	fout.close();
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			unit* pUnit = new unit();
			r.input(pUnit);
			break;
		}
		case 2:
		{
			r.output();
			break;
		}
		case 3:
		{
			r.outputf();
			break;
		}
		case 4:
		{
			r.inputf();
			break;
		}
		case 5:
		{
			r.clear();
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Введите правильную цифру!" << endl;
		}
		}
	}
    //int nRetCode = 0;

    //HMODULE hModule = ::GetModuleHandle(nullptr);

    //if (hModule != nullptr)
    //{
    //    // инициализировать MFC, а также печать и сообщения об ошибках про сбое
    //    if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
    //    {
    //        // TODO: вставьте сюда код для приложения.
    //        wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
    //        nRetCode = 1;
    //    }
    //    else
    //    {
    //        // TODO: вставьте сюда код для приложения.
    //    }
    //}
    //else
    //{
    //    // TODO: измените код ошибки в соответствии с потребностями
    //    wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
    //    nRetCode = 1;
    //}

    //return nRetCode;
}
