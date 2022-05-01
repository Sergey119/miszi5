#include <iostream>	// для оператора cout
#include <cctype>   // для функции isdigit
#include "windows.h"// для функции Sleep()
#include <vector>	// для структуры node
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // для функции atoi
#include <stdio.h>

//Выравнивание потока
void stream_equalization(int originalNumber/*, char * str*/)
{
	//int atoi(*str);
	int amountOf0 = 0;
	int copyOriginalNumber = originalNumber;
	//Перевод из десятичной
	//с.с. в двоичную, но
	//задом наперед
	int changeling = 0;
	while (originalNumber)
	{
		changeling = changeling * 10 +
			(originalNumber % 2);
		//std::cout << "originalNumber: " << originalNumber << std::endl;
		/*if (originalNumber % 2 == 0)
			amountOf0++;
		if (((originalNumber / 2) % 2) == 1)
			amountOf0 = 0;
		std::cout << "amountOf0: " << amountOf0 << std::endl;*/
		originalNumber /= 2;
	}
	originalNumber = copyOriginalNumber;
	if (originalNumber % 2 == 0)
		while (originalNumber % 2 == 0)
		{
			amountOf0++;
			originalNumber /= 2;
		}
	std::cout << "amountOf0: " << amountOf0 << std::endl;
	//Переворачиваем 
	//двоичное число,
	//записанное наоборот
	int binaryNumber = 0;
	while (changeling)
	{
		binaryNumber = binaryNumber * 10 +
			(changeling % 10);
		changeling /= 10;
	}
	//Если были в конце
	//числа нули, их
	//нужно дописать
	std::cout << "binaryNumber до: " << binaryNumber << std::endl;
	if (amountOf0 != 0)
		for (int i = 0; i < amountOf0; i++)
		{
			binaryNumber = binaryNumber*10;
		}

	std::cout << "binaryNumber после: " << binaryNumber << std::endl;

	binaryNumber = binaryNumber * 10 + 1;
	std::cout << "binaryNumber & add one bit: " << binaryNumber << std::endl;
	originalNumber = copyOriginalNumber;
	int moduloNumber = originalNumber;
	/*while (originalNumber % 512 != 448)
	{
		binaryNumber = binaryNumber * 10;
		std::cout << "binaryNumber: " << binaryNumber;
	}*/
	while (moduloNumber % 512 != 448)
		moduloNumber++;
		
	std::cout << "difference between original and modulo number: "
		<< (moduloNumber-originalNumber) << std::endl;
	
}

int main()
{
	char s[] = "2, 38.5, 70, 0, 0, 1", *p = s;
	double m[10];
	int i = 0;
	do {
		m[i++] = atof(p);
		if (i > 9)break;
	} while (p = strchr(p, ','), p++);
	for (int k = 0; k < i; k++)
		printf("%5.2f ", m[k]);
	setlocale(LC_ALL, "Russian");
	int acceptedNumber = 0;
	std::cin >> acceptedNumber;
	std::cout << std::endl;
	stream_equalization(acceptedNumber);
}
