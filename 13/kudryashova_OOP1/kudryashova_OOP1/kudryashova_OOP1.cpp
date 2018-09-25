// kudryashova_OOP1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "kudryashova_OOP1.h"
#include "fitness_club.h"
#include "client.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������������ ������ ����������

CWinApp theApp;

using namespace std;

int menu()
{
	cout << "1:add" << endl;
	cout << "2:print" << endl;
	cout << "3:save" << endl;
	cout << "4:load" << endl;
	cout << "5:clear" << endl;
	cout << "0:exit" << endl;
	int n;
	cin >> n;
	return n;
}

void start()
{
	fitness_club fc;
	while (1)
	{
		switch (menu())
		{
		case 1:
		{
			client* pCl = new client();
			fc.add(pCl);
			break;
		}
		case 2:
		{
			fc.print();

			break;
		}
		case 3:
		{
			fc.write();
			break;
		}
		case 4:
		{
			fc.read();
			break;
		}
		case 5:
		{
			fc.clear();
			break;
		}
		default:
		{
			return;
		}
		}
	}
}

int main()
{
    //int nRetCode = 0;

    //HMODULE hModule = ::GetModuleHandle(nullptr);

    //if (hModule != nullptr)
    //{
    //    // ���������������� MFC, � ����� ������ � ��������� �� ������� ��� ����
    //    if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
    //    {
    //        // TODO: �������� ��� ������ �������������� ����� ������������
    //        wprintf(L"����������� ������: ���� ��� ������������� MFC\n");
    //        nRetCode = 1;
    //    }
    //    else
    //    {

			start();
    //        // TODO: �������� ���� ��� ��� ����������.
    //    }
    //}
    //else
    //{
    //    // TODO: �������� ��� ������ �������������� ����� ������������
    //    wprintf(L"����������� ������: ��������� ���������� GetModuleHandle\n");
    //    nRetCode = 1;
    //}

    //return nRetCode;
			return 0;
}
