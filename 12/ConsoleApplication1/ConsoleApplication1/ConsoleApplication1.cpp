// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void minArray(vector<int> arr, int& minimum, size_t& position);

int main() 
{
	size_t N;
	std::cout << "Input N" << endl;
	cin >> N;
	vector<int> arr(N);

	for (size_t i = 0; i < arr.size(); ++i)
	{
		cout << "Input " << i << " element: ";
		cin >> arr[i];
	}
	int min;
	size_t pos;
	minArray(arr, min, pos);

	cout << "Minimum of array is: " << min << ". It is on position: " << pos + 1 << endl;
}

void minArray(vector<int> arr, int& minimum, size_t& position)
{
	minimum = arr[0];
	position = 0;
	
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i] < minimum)
		{
			minimum = arr[i];
			position = i;
		}
	}
}
