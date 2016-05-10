#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct
{
	void *data;
} stdata;
typedef stdata* pdata;

void copy(pdata p, void* data, int dsize)
{
	p->data = malloc(dsize);
	memcpy(p->data, data, dsize);
}
int main()
{
	pdata p = malloc(sizeof(stdata));
	int a = 5;
	copy(p, &a, sizeof(int));
	printf("Data: %d\n", *((int*)p->data));
}