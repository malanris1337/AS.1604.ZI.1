// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "Lab1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp TheApp;

// Единственный объект приложения

int menu()
{
	cout << "/1/ add new car\n/2/ print all cars\n/3/ save into the (file.dat)\n/4/ load from the (file.dat)\n/5/ clear all cars in console\n/0/ exit\n";
	int n;
	cin >> n;
	return n;
}

void start()
{
	carshowroom crs;
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			cars* pcar = new cars();
			crs.add(pcar);
			break;
		}
		case 2:
		{
			crs.print();

			break;
		}
		case 3:
		{
			crs.write();
			break;
		}
		case 4:
		{
			crs.read();
			break;
		}
		case 5:
		{
			crs.clear();
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "\n//////////////////////////////\nEnter the correct number (0-5)\n//////////////////////////////\n\n";
		}
		}
	}
}




int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
	    // инициализировать MFC, а также печать и сообщения об ошибках про сбое
	    if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
	    {
	        // TODO: измените код ошибки соответственно своим потребностям
	        wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
	        nRetCode = 1;
	    }
	    else
	    {

	start();
	        // TODO: Вставьте сюда код для приложения.
	    }
	}
	else
	{
	    // TODO: Измените код ошибки соответственно своим потребностям
	    wprintf(L"Критическая ошибка: неудачное завершение GetModuleHandle\n");
	    nRetCode = 1;
	}

	return nRetCode;
	return 0;
}