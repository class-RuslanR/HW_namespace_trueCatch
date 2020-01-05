#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "letters.h"
#include "digits.h"

using namespace std;
using namespace Let;
using namespace Dig;

int main()
{
	setlocale(LC_ALL, "ru");

	char file[] = "FileForRead.txt";
	ifstream inFile;
	inFile.exceptions(ifstream::badbit | ifstream::failbit);
	
	try
	{
		cout << "Считывание файла, отделение букв и цифр из строк, и операции на ними" << endl;
		inFile.open(file);
		char *str = new char[50];
		while (!inFile.eof())
		{
			inFile.getline(str, 50);
			cout << str << endl;
			int size = inFile.gcount();
			//cout << size << endl;
			/////////////////////////////////////////////////
			// ВЫВОД ТОЛЬКО БУКВ
			char * strLet = new char[size];
			strLet = Let::onlyLetters(str, size);
			//int size_strLet = strlen(strLet);
			for (int i = 0; i < size; i++)
			{
				cout << strLet[i] << " ";
			}
			cout << "\n\n";

			////////////////////////////////////////////////
			//СОРТИРОВКА БУКВ ПО АЛФАВИТУ
			char * strLetSort = new char[size];
			strLetSort = Let::onlyLettersSortAlpha(strLet, size);
			for (int i = 0; i < size; i++)
			{
				cout << strLetSort[i] << " ";
			}
			cout << "\n\n";


			/////////////////////////////////////////////////
			//ВЫВОД ТОЛЬКО ЦИФР
			char * strDig = new char[size];
			strDig = Dig::onlyDigits(str, size);
			//int size_strDig = strlen(strDig);
			for (int i = 0; i < size; i++)
			{
				cout << strDig[i] << " ";
			}
			cout << "\n\n";

			////////////////////////////////////////////////
			// РЕЗУЛЬТАТ ДЕЛЕНИЯ ПРЕДЫДУЩЕЙ НА ПОСЛЕДУЮЩУЮ ЦИФРУ
			/*double * strDigDelenie = new double[size];
			double * strDigDouble = new double[size];
			strDigDouble[0] = 0;
			for (int j = 0; j < size; j++)
			{
				strDigDouble[j] = atof((char*)strDig[j]);
			}
			strDigDelenie = Dig::onlyDigitsDelenie(strDigDouble, size);
			for (int i = 0; i < size; i++)
			{
				cout << strDigDelenie[i] << " ";
			}
			cout << "\n\n";*/
			
			//delete strDigDelenie;
			delete strLet;
			//delete strLetSort;
			delete strDig;
		}
		
		delete str;
	}
	catch (const ifstream::failure &ex)
	{
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cerr << "Ошибка открытия файла" << endl;
	}

	inFile.close();
	system("pause");
	return 0;
}

/*if (!inFile)
	{
		cerr << "Ошибка открытия файла" << endl;
	}
	else
	{
		char *str = new char[50];
		while (!inFile.eof())
		{
			inFile.getline(str, 50);
			cout << str << endl;
		}
		delete str;
	}*/


