#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Let
{
	/*void onlyLetters(char*mass, int length)
	{
		for (int i = 0; i < length; i++)
		{
			if (mass[i] >= 'a' && mass[i] <= 'z')
			{
				cout << mass[i] << " ";
			}
		}
		cout << "\n\n";
	}*/

	char * onlyLetters(char*mass, int length)
	{

		char *mass_copy = new char[length];
		mass_copy[0] = 0;
		for (int i = 0; i < length; i++)
		{
			if (mass[i] >= 'a' && mass[i] <= 'z')
			{
				mass_copy[i] = mass[i];
			}
		}
		return mass_copy;
	}

	char * onlyLettersSortAlpha(char*mass, int length)
	{
		char *buf = new char[length];
		buf[0] = 0;
		for (int j = 1; j < length; j++)
		{
			for (int i = 0; i < length - j; i++)
			{
				if ((int)mass[i] > (int)mass[i+1])
				{
					buf[i] = mass[i];
					mass[i] = mass[i + 1];
					mass[i + 1] = buf[i];
				}
			}
		}
		return mass;
	}
}

//strcmp((const char*)mass[i], (const char*)mass[i + 1]) == 1