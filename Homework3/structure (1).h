#ifndef _structure_h_
#define _structure_h_

#include "stock.h"
//structure to define stack
typedef struct STACK{
    int top;
    stock *head;
}stack;
stack *st;

//Adds stock structure s at top of st[index]
void push(stock *s,int index) ;
stock* copy(stock *s);
//Removes stock structure from st[index]
stock* pop(int index);
// Print stack
void printStack(stock *s);

typedef struct queue{
    stock *front,*rear;
}queue;

queue *q;
//function to add stock structure s to q[index]
void enQueue(stock *s,int index);
// Function to remove a stock structure from q[index]
stock *deQueue(int index);

#endif
