#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float f0(float x)
{
	float res = 1 - exp(-x);
	res = res * cos(x);
	return res;
}
float f1(float x)
{
	float res = exp(-x);
	res = res * (cos(x) + sin(x));
	res = res - sin(x);
	return res;
}
float f2(float x)
{
	float res = -2 * exp(-x) * sin(x) ;
	res = res - cos(x);
	return res;
}

float f3(float x)
{
	float res = sin(x) + 2 * exp(-x) * (sin(x) - cos(x));
	return res;
}
float f4(float x)
{
	float res = (4 * exp(-x) + 1) * cos(x);
	return res;
}
float f5(float x)
{
	float res = -sin(x) - 4 * exp(-x) * (cos(x) + sin(x));
	return res;
}
int fac(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++) res *= i;
	return res;
}
float taylor(float x, int level)
{
	float res = 0;
	switch (level)
	{
		case 1:
			res = f0(0) + f1(0) * x;
			break;
		case 2:
			res = f0(0) + f1(0) * x + f2(0) * x * x / (fac(2));
			break;
		case 3:
			res = f0(0) + f1(0) * x + f2(0) * x * x / fac(2) + f3(0) * x * x * x / fac(3) ;
			break;
		case 4:
			res = f0(0) + f1(0) * x + f2(0) * x * x / fac(2) + f3(0) * x * x * x / fac(3) + f4(0) * x * x * x * x / fac(4);
			break;
		case 5:
			res = f0(0) + f1(0) * x + f2(0) * x * x / fac(2) + f3(0) * x * x * x / fac(3) + f4(0) * x * x * x * x / fac(4);
			res += f5(0) * x * x * x * x * x / fac(5);
			break;
		default:
			throw "Not a correct level";
	}
	return res;
}

int main(int argc, char** argv) 
{
	int choice = 1;
	int level;
	float eps, rexacte, rsere;
	cout << "Evaluate the Taylor Series approximation to (1-exp(-t))*cos(t)" << endl;
	while (choice == 1) 
	{	
		cout << "1: Evaluate the series" << endl;
		cout << "2: Quit" << endl;
		cin  >> choice;
		if (choice != 1) break;
		cout << "Evaluating the series" << endl;
		cout << "Please enter the highest power of t in the series (1, 2, 3 or 4): ";
		cin  >> level;
		cout << "Please enter the range of t to evaluate in 10 increments( 0.0 < t < +1.0): ";
		cin  >> eps;
		eps = eps / 10.0;
		cout << "MACLAURIN SERIES" << endl;
		cout << setw(15) << "t" << setw(15) << "F(t) Series" << setw(15) << "F(t) Exact" << setw(15) << "%RExactE" << setw(15);
		cout << "%RSerE" << endl;
		for (int i = 0; i < 11; i++)
		{
			float fseries = taylor(eps*i,level);
			float fexact  = f0(eps*i);
			float fseries2 = taylor(eps*i, level+1);
			cout << std::scientific << setw(15) << eps * i << setw(15) << fseries << setw(15) << f0(eps*i);
			if (fexact != 0) rexacte = -100*(fseries - fexact)/fexact;
			else rexacte = 0.0;
			if (fseries != 0) rsere = 100*(fseries2 - fseries)/fseries;
			else rsere = 0.0;
			cout << setw(15) << rexacte << setw(15) << rsere << endl;
		}
	}
	
	cout << taylor(0.1, 1) << endl;
	cout << f0(0.1) << endl;
	return 0;
}

