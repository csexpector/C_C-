#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int binomial(int k, int n);
int main(int argc, char** argv) {
	int k = 4, n = 5;
	printf("(%d, %d) = %d", k, n, binomial(k,n));
	return 0;
}

int binomial(int k, int n)
{
	if (k == 0) return 1;
	if (k == n) return 1;
	else return binomial(k-1, n-1) + binomial(k,n-1);
}
