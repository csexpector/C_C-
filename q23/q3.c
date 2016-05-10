#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n , i, j;
	char c;
	double x, cosx, xpower, nfac;
	while (1)
	{
		cosx = 1; 
		xpower = 1;
		nfac = 1;
		printf("Enter x: ");
		scanf("%lf", &x);
		printf("Enter n-terms: ");
		scanf("%d",&n);
		fflush(stdin);
		if (n < 1) 
		{
			printf("n must be positive\n");
			break;
		}
		else
		{
			for (i = 1; i <= n; i++)
			{
				xpower = xpower * x * x;
				nfac = nfac * (2*i-1);
				nfac = nfac * 2 * i;
				if (i % 2 == 0) cosx += xpower / nfac;
				else cosx -= xpower / nfac;
			}
			printf("cosx = %.5f\n", cosx);
		}
		while (1)
		{		
			printf("Do you wish to quite (y/n): ");
			scanf("%c", &c);
			if (c == 'y') return 0;
			if (c == 'n') break;
		}
	}
	return 0;
}
