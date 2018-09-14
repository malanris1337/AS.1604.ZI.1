// MarkinaAS1604L1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MarkinaAS1604L1.h"
#include "c_airport.h"
#include "c_plane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void MainMenu()
{
	cout << "1: Add plane" << endl;
	cout << "2: Add airport" << endl;
	cout << "3: Print information about airport" << endl;
	cout << "4: Delete airport" << endl;
	cout << "5: Delete all planes in airport" << endl;
	cout << "6: Exit" << endl;
}

void master_m()
{
	c_airport myAirport;

	int p_menu;
	while (1) {
		MainMenu();
		cin >> p_menu;
		switch (p_menu)
		{
		case 2: { myAirport.AddAirport();
			break;
		}
		case 3: { myAirport.PrintAirport();
			break;
		}
		default:
			break;
		}

	}
}
// Единственный объект приложения

CWinApp theApp;

using namespace std;

int main()
{
	master_m();
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
}
