// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//void (vector<char> arr);

void Input()
{
	ifstream in("1.txt");
	vector<char> arr;
	size_t i;
	while (!in.eof())
	{
		arr.push_back(i);
		for (size_t j=1; j < arr.size(); ++j)
			cout << arr[j] << " ";
	}
}



int main() 
{
	Input();
	return 0;



}

//void minArray(vector<char> arr)
//{
//	minimum = arr[0];
//	position = 0;
//	
//	for (size_t i = 1; i < arr.size(); ++i)
//	{
//		if (arr[i] < minimum)
//		{
//			minimum = arr[i];
//			position = i;
//		}
//	}
//}
//void Output(vector<char> arr)
//{
//	cout << "Array is: ";
//	for (size_t i = 0; i < arr.size(); i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//}