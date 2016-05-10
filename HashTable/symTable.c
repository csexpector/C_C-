#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include "symTable.h"
#define HASH_MULTIPLIER 65599
#define DEFAULT_TABLE_htsize 61

/*--------------------------------------------------------------------*/

int htsize = 61;

struct SymTable {
	char *key;				
	void *value;				
	struct SymTable *next;	
};


/* Return a copy of string str, converted to lower-case */

char *lowercase(const char *str)
{
	char *word, *ptr;

	if ((word = strdup(str)) != NULL) {
		for (ptr = word; *ptr != '\0'; ptr++)
			*ptr = tolower(*ptr);
	}
	return word;
}

/*--------------------------------------------------------------------*/

/* Hash string str to a hash table bucket index in range [0, htsize-1] */

unsigned int hash(const char *key, const int htsize)
{
	int i;
	unsigned int h = 0U;
	for (i = 0; key[i] != '\0'; i++)
		h = h * HASH_MULTIPLIER + (unsigned char)key[i];
	return h % htsize;
}

//CREATE

SymTable_T symTable_create(void)
{
	SymTable_T p;
	p = calloc(htsize, sizeof(SymTable_T));
	p->key = (char*)calloc(1, sizeof(char));

	return p;
}

//DESTROY

void symTable_destroy(SymTable_T symTable)
{
	SymTable_T p, nextp;
	int i;

	assert(symTable != NULL);

	for (i = 0; i < htsize; i++) {
		for (p = symTable; p != NULL; p = nextp) {
			nextp = p->next;
			assert(p->key != NULL);
			p=NULL;
		}
	}
	free(symTable);
	return;

}

//SIZE

int symTable_size(SymTable_T symTable)
{

	SymTable_T p, nextp;
	int i = 0;
	assert(symTable != NULL);
	for (p = symTable; p != NULL; p = p->next) {
			//nextp = p->next;
			i++;
	}

	return i;

}

//INSERT

int symTable_insert(SymTable_T symTable, const char *key, const void *value, size_t valuesize)
{

	SymTable_T p, prevp;
	int h;


	assert(symTable != NULL);

	if (key == NULL)
		return 0;					// insert failed: return 0

	/* Get hash of key*/
	h = hash(key, htsize);

	/* Search for lowercaseword in its hash table bucket */

	for (p = symTable; p != NULL; prevp = p, p = p->next) {

		if (hash(p->key, htsize) == h)
		{
			//free(key);
			return 0;
		}

	}
	// create a new one
	//p = (SymTable_T *)malloc(sizeof(SymTable_T));
	p = (SymTable_T)malloc(sizeof(struct SymTable));
	if (p == NULL)
		return 0;
	//p->key = key;	// set p->key to point to lowercaseword
	p->key = (char *)malloc(sizeof(char)*strlen(key));
	memcpy(p->key, key, strlen(key));
	//p->value = (void*)calloc(1, valuesize);
	p->value = malloc(valuesize);
	memcpy(p->value, value, valuesize);
	p->next = NULL;
	if (symTable == NULL)
		symTable = p;
	else
		prevp->next = p;
	return 1;
}

//SEARCH

int symTable_search(SymTable_T symTable, const char *key,
	void *value, size_t valuesize)
{

	SymTable_T p, nextp;
	int i;
	assert(symTable != NULL);
	//for (i = 0; i < htsize+1; i++) {

		for (p = symTable->next; p != NULL; p = p->next) 
		{
			printf("Compare %s vs %s\n", p->key, key);
			if (strcmp(p->key, key) == 0)
			{
				//value = (p->value) ;
				//printf("Found, value = %d\n", *p->value);
				memcpy((p->value), value, valuesize);
				return 1;
			}

		}
	//}
	return 0;

}

//DELETE

int symTable_delete(SymTable_T symTable, const char *key)
{
	SymTable_T p, nextp;
	int i;
	assert(symTable != NULL);
	for (i = 0; i < htsize; i++) {
		for (p = symTable->next; p != NULL; p = nextp) {
			nextp = p->next;

			assert(p->key != NULL);
			if (strcmp(p->key, key) == 0)
			{

				p = NULL;
				return 1;
			}
		}
	}
	return 0;
}
