
#include "structure.h"
//structure to define stack

//Adds stock structure s at top of st[index]
void push(stock *s,int index) {
    s->next = st[index].head;
    st[index].head = s;
    st[index].top++;
}
stock* copy(stock *s)
{
	stock* snew = (stock*)malloc(sizeof(stock));
	snew->price = s->price;
	snew->purchase = s->purchase;
	strcpy(snew->name, s->name);
	strcpy(snew->symbol, s->symbol);
	return snew;
}
//Removes stock structure from st[index]
stock* pop(int index){
    stock *s = st[index].head;
    st[index].head=s->next;
    return s;
}

void printStack(stock *s)
{
	if (s != NULL) {
		printf("Symbol: %s\n", s->symbol);
		printf("Name: %s\n", s->name);
		printf("Purchage: %d\n", s->purchase);
		printf("Price: %.2f\n", s->price);
		printf("-----\n");		
	}
}

//function to add stock structure s to q[index]
void enQueue(stock *s,int index)
{
    // If queue is empty, then new node is front and rear both
    if (q[index].rear == NULL)
    {
       q[index].front = q[index].rear = s;
       return;
    }

    // Add the new node at the end of queue and change rear
    q[index].rear->next = s;
    q[index].rear = s;
}

// Function to remove a stock structure from q[index]
stock *deQueue(int index)
{
    // If queue is empty, return NULL.
    if (q[index].front == NULL)
       return NULL;

    // Store previous front and move front one node ahead
    stock *temp = q[index].front;
    q[index].front = q[index].front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q[index].front == NULL)
       q[index].rear = NULL;
    return temp;
}

