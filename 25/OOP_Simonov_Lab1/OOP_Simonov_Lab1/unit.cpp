#include "pch.h"
#include "unit.h"


unit::unit()
{
}


unit::~unit()
{
}


void unit::input()
{
	cout << "������� ��� ���" << endl;
	cin >> r_type;
	cout << "������� ����� ���" << endl;
	cin >> r_size;
	cout << endl << endl;
}



void unit::output()
{
	cout << "��� ���: ";
	cout << r_type << endl;
	cout << "����� ���: ";
	cout << r_size << endl;
	cout << endl << endl;
}


void unit::inputf(ifstream& fin)
{
	fin >> r_type;
	fin >> r_size;
}


void unit::outputf(ofstream& fout)
{
	fout << r_type << endl;
	fout << r_size << endl;
}
