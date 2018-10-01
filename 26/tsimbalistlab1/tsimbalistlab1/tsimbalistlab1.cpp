// tsimbalistlab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tsim_player.h"
#include "tsim_team.h"
#include "tsimbalistlab1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

using namespace std;
int menu()
{
	cout << "1:Add player" << endl;
	cout << "2:Print team" << endl;
	cout << "3:Read from file" << endl;
	cout << "4:Write in file" << endl;
	cout << "5:Clear" << endl;
	cout << "0:Exit" << endl;
	int n;
	cin >> n;
	return n;
}
void start()
{
	tsim_team ptm;
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			tsim_player*tpl = new tsim_player;
			ptm.add(tpl);
			break;
		}
		case 2:
		{
			ptm.print();
			break;
		}
		case 3:
		{
			ptm.read();
			break;
		}
		case 4:
		{
			ptm.write();
			break;
		}
		case 5:
		{
			ptm.clear();
			break;
		}
		case 0:
		{
			break;
		}
		{
		default:
			break;
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
			start();// TODO: Вставьте сюда код для приложения.
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
