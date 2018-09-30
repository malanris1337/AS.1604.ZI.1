#include "pch.h"
#include "RAM.h"
#include "unit.h"


RAM::RAM()
{
}


RAM::~RAM()
{
	clear();
}


void RAM::outputf()
{
	ofstream fout("out.txt");
	if (fout.is_open())
	{
		fout << "Всего единиц: " << units.size() << endl << endl;
			for (auto &pUnit : units)
			{
				pUnit->outputf(fout);
			}
	}
	else
	{
		cout << "Файл не найден!" << endl;
	}
}


void RAM::input(unit* pUnit)
{
	pUnit->input();
	units.push_back(pUnit);
}


void RAM::inputf()
{
	ifstream  fin("input.txt");
	if (fin.is_open())
	{
		int n;
		fin >> n;
		for (int i = 0; i < n; ++i)
		{
			unit* pUnit = new unit;
			pUnit->inputf(fin);
			units.push_back(pUnit);
		}
	}
	else
	{
		cout << "Файл не найден!" << endl;
	}
	
}


void RAM::output()
{
	for (auto &pUnit : units)
	{
		pUnit->output();
	}
}


void RAM::clear()
{
	for (auto &pUnit : units)
	{
		delete pUnit;
	}
	units.clear();
}
