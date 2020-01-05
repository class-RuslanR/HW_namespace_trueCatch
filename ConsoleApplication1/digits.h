#pragma once
#include <iostream>

using namespace std;

namespace Dig
{
	char * onlyDigits(char*mass, int length)
	{
		char *mass_copy = new char[length];
		mass_copy[0] = 0;
		for (int i = 0; i < length; i++)
		{
			if (mass[i] >= '0' && mass[i] <= '9')
			{
				mass_copy[i] = mass[i];
			}
		}
		return mass_copy;
		//delete[] mass_copy;
	}

	/*double * onlyDigitsDelenie(double*mass, int length)
	{
		double *mass_copy = new double[length];
		mass_copy[0] = 0.0;
		for (int i = 0; i < length; i++)
		{
			mass_copy[i] = mass[i] / mass[i + 1];
		}
		return mass_copy;
		//delete[] mass_copy;
	}*/

}