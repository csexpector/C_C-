#ifndef _stock_h_
#define _stock_h_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

//structure to define the data members of stock and creation of linked list
typedef struct STOCK{
    char symbol[MAX_SIZE];
    char name[MAX_SIZE];
    int purchase;
    double price;
    struct STOCK *next;
}stock;

#endif
