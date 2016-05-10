#include <iostream>
#include <stdio.h>
using namespace std;

// declare Node type
typedef struct strNode
{
	int data;
	strNode* pNext;
} Node;

// declare stack operation
Node* Pop();
void  Push(Node* p);
// declare queue operation
void  Enqueue(Node* p);
Node* Dequeue();

// declare a stack
Node* pHeadStack = NULL;
// declare a queue with Head and Tail
Node* pHeadQueue = NULL;
Node* pTailQueue = NULL;

// declare createNode function. This will create a Node with data
Node* createNode(int data);
// declare printList function
void printList(Node* p);
// declare printStack function
void printStack();
// declare printQueue function
void printQueue();
// main function
int main(int argc, char** argv) 
{
	Node* p;
	int opt, data;
	char c;
	cout << " ** STACK QUEUE DEMO **" << endl;
	while (true)
	{
		cout << "Choose 1 option bellow: " << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop"  << endl;
		cout << "3. Enqueue" << endl;
		cout << "4. Dequeue" << endl;
		cout << "5. Print stack" << endl;
		cout << "6. Print queue"  << endl;
		cout << "7. Exit" << endl;
		cout << "Your choice: ";
		cin >> opt;
		switch (opt)
		{
			case 1:
				cout << "Enter new data: ";
				cin  >> data;
				p = createNode(data);
				Push(p);
				cout << data << " is pushed to stack" << endl;
				break;
			case 2:
				p = Pop();
				if (p != NULL) cout << p->data << " is poped out of stack"  << endl;
				break;
			case 3:
				cout << "Enter new data: ";
				cin  >> data;
				p = createNode(data);
				Enqueue(p);
				cout << data << " is enqueued" << endl;
				break;
			case 4: 
				p = Dequeue();
				if (p != NULL) cout << p->data << " is dequeued"  << endl;
				break;
			case 5:
				cout << "Current stack:" << endl;
				printStack();
				break;
			case 6:
				cout << "Current queue:" << endl;
				printQueue();
				break;
			case 7:
				return 0;
			default:
				cout << "Wrong option!" << endl;
		}
		
		cout << "Press enter to continue!";
		cin.get(); // this is to bypass the '\n' character from last cin
		cin.get(); // stop the screen to see output
	}
	return 0;
}

// implement stack Pop operation
Node* Pop()
{
	Node* p = pHeadStack;
	
	if (p == NULL) return p;	// Stack is emptied
	else if (p->pNext == NULL)  // Stack has only one element
	{
		pHeadStack = NULL;
		return p;
	}
	else  // Stack has more than 1 element
	{
		pHeadStack = pHeadStack->pNext;
		p->pNext = NULL;
		return p;
	}
}
// implement stack Push operation
void Push(Node* p)
{
	if (p == NULL) return;		// p is NULL do nothing
	if (pHeadStack == NULL) pHeadStack = p;	// Stack is emptied
	else // Stac is not emptied
	{
		p->pNext = pHeadStack;
		pHeadStack = p;
	}
}
void  Enqueue(Node* p)
{
	if (p == NULL) return;	// p is NULL do nothing
	if (pHeadQueue == NULL) // Queue is emptied
	{
		pHeadQueue = p;
		pTailQueue = p;
	}
	else // Queue is not emptied
	{
		// add p to tail of queue
		p->pNext = pTailQueue;
		pTailQueue = p;
	}
	
}
Node* Dequeue()
{
	Node* p = pHeadQueue;
	if (p == NULL) return p;
	if (pHeadQueue == pTailQueue) // Queue has only 1 element
	{
		// make queue emptied
		pHeadQueue = NULL;
		pTailQueue = NULL;
		return p;
	}
	else // more than 1 element
	{
		// remove element in head of queue
		Node* q = pTailQueue;
		// find element which stands a head of pHeadQueue
		while (q->pNext != pHeadQueue) q = q->pNext; 
		// remove head
		pHeadQueue = q;
		q->pNext = NULL;
		return p;
	}
}
Node* createNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	return p;
}
void printList(Node* p)
{
	// print node one after another
	while (p != NULL)
	{
		cout << "(" << p->data << ")" << "-->";
		p = p->pNext;
	}
	cout << "NULL" << endl;
}
void printStack()
{
	// print stack from head
	printList(pHeadStack);
}
void printQueue()
{
	// print queue from tail
	printList(pTailQueue);
}
