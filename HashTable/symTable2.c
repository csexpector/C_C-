#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include "symTable.h"
#define HASH_MULTIPLIER 65599
#define DEFAULT_TABLE_htsize 61
const int htsize = 61;
struct SymTable {
	char *key;				
	void *value;				
	struct SymTable *next;	
};
unsigned int hash(const char *key, const int htsize)
{
	int i;
	unsigned int h = 0U;
	for (i = 0; key[i] != '\0'; i++)
		h = h * HASH_MULTIPLIER + (unsigned char)key[i];
	return h % htsize;
}
SymTable_T symTable_create(void)
{
	SymTable_T p = (SymTable_T)malloc(sizeof(SymTable));
	p->key = NULL;
	p->value = NULL;
	p->next = NULL;
	
	return p;
}

int symTable_insert(SymTable_T symTable, const char *key, const void *value, size_t valuesize)
{
	int hvalue;
	assert(symTable != NULL);
	if (key == NULL)		return 0;
	
	hvalue = hash(key, htsize);
	
	
}
