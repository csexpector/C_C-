// NumberFun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	// n is input integer
	// m is output integer
	// d is last digit
	// k is the factor (11 if n is odd, 111 if n is even)
	long long n, m = 0, d, k;
	// c is the answer (y/n)
	char c;
	// loop until c is n
	while (true)
	{
		// reset m each run
		m = 0;
		cout << "Enter an integer: ";
		cin >> n;
		if (n % 2 == 1)	// n is odd
		{
			k = 11;
			while (n != 0)
			{
				// get the last digit
				d = n % 10;
				// remove the last digit
				n = n / 10;
				// update new number = old number + last digit * 1100...00
				m = m + d * k;
				// update factor
				k = k * 100;
			}
			cout << "Number is odd, doubling each digit in the integer ..." << endl;
			cout << "Result: " << m << endl;
		}
		else // n is even
		{
			k = 111;
			while (n != 0)
			{
				// get the last digit
				d = n % 10;
				// remove the last digit
				n = n / 10;
				// update new number = old number + last digit * 111000...000
				m = m + d * k;
				// update factor
				k = k * 1000;
			}
			cout << "Number is even, tripling each digit in the integer ..." << endl;
			cout << "Result: " << m << endl;
		}
		cout << "Would you like to enter another integer (y/n): ";
		cin >> c;
		if (c == 'n') break;
	}
	
	return 0;
}

