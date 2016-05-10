#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a, eps, xnew, xprev;
	int i = 0;
	printf("Enter a number: ");
	scanf("%lf", &a);
	eps = a * 0.000001;
	if (a == 0.0)
	{
		printf("Square %.5f = %.5f\n", a, a);
	}
	else
	{
		xnew = a/2.0;
		xprev = a;
		
		while (fabs(xprev - xnew) > eps)
		{
			i++;
			double tmp = xprev;
			xprev = xnew;
			xnew = (tmp + a / tmp)/2.0;			
		}
		printf("Square %.5f = %.6f, check: %.5f, loop: %d\n", a, xnew, sqrt(a), i);
	}
	return 0;
}
