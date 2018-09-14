// MarkinaAS1604L1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
// ������������ ������ ����������

CWinApp theApp;

using namespace std;

int main()
{
	master_m();
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // ���������������� MFC, � ����� ������ � ��������� �� ������� ��� ����
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: �������� ��� ������ �������������� ����� ������������
            wprintf(L"����������� ������: ���� ��� ������������� MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: �������� ���� ��� ��� ����������.
        }
    }
    else
    {
        // TODO: �������� ��� ������ �������������� ����� ������������
        wprintf(L"����������� ������: ��������� ���������� GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
