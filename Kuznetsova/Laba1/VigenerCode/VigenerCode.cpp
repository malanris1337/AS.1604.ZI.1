// VigenerCode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "functions.h"


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	if (argc < 4)
		return 0;
	string s1, s2, s3;
	s1 = argv[1];
	s2 = argv[2];
	s3 = argv[3];
	int res = f(s1, s2, s3);
	return 0;
}



