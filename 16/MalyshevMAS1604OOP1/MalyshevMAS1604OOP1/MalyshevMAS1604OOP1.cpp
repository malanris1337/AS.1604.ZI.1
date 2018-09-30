// MalyshevMAS1604OOP1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Shop.h"
#include "Product.h"
#include "MalyshevMAS1604OOP1.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


// Единственный объект приложения

//CWinApp theApp;

using namespace std;

void menu()
{
	Shop sh;
	while (1)
	{
		cout << "1 -> Add product" << endl;
		cout << "2 -> Read from file" << endl;		
		cout << "3 -> Save to file" << endl;
		cout << "4 -> Print out all" << endl;
		cout << "5 -> Clear" << endl;
		cout << "0 -> Exit" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			Product* pr = new Product();
			sh.add_product(pr);
			break;
		}
		case 2:
		{
			sh.read_from_file();
			break;
			
		}
		case 3:
		{
			sh.write_to_file();
			break;
		}
		case 4:
		{
			sh.print_out_all();
			break;
		}
		case 5:
		{
			sh.clear();
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Incorrect value!" << endl;
			cout << endl;
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
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
    //   if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
    //    {
            // TODO: измените код ошибки соответственно своим потребностям
    //        wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
    //        nRetCode = 1;
    //    }
    //    else
    //    {
            // TODO: Вставьте сюда код для приложения.
		menu();
    //   }
    //}
    //else
    //{
        // TODO: Измените код ошибки соответственно своим потребностям
    //    wprintf(L"Критическая ошибка: неудачное завершение GetModuleHandle\n");
    //    nRetCode = 1;
    //}

    //return nRetCode;
		return 0;
}
