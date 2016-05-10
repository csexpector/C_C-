#include <iostream>
#define MAXLEN 100
// main function
int arr[MAXLEN];
int length = 0;
using namespace std;
void insert();
void delete_node();
void find();
void print();
int main()
{
	int choice;
	while (1)
	{
		cout << endl << "Menu Options" << endl;
		cout << "=============" << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Delete a Node" << endl;
		cout << "3. Find a Node" << endl;
		cout << "4. Print all Nodes" << endl;
		cout << "5. Exit " << endl << endl;
		cout << "Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Inserting Node: " << endl;
			insert();
			cout << endl;
			break;
		case 2:
			cout << "Delete a Node: " << endl;
			delete_node();
			break;
		case 3:
			cout << "Find a Node: " << endl;
			find();
			cout << endl;
			break;
		case 4:
			cout << "Print all Nodes:  " << endl;
			print();
			cout << endl;
			break;
		case 5:
			cout << "Exiting..." << endl;
			exit(1);
			break;
		default:
			cout << "Invalid Choice!" << endl;
		}
	}
}
void insert()
{
	if (length == MAXLEN)
	{
		cout << "Max capacity! Couldn't insert!" << endl;
		return;
	}
	
	int data;
	cout << "Enter the data of node: ";
	cin >> data;
	if (length == 0)
	{
		arr[0] = data;
		length = 1;
		return;
	}
	int i;
	for (i = 0; i < length; i++)
	{
		if (arr[i] > data)
		{
			for (int j = length - 1; j >= i; j--) arr[j+1] = arr[j];
			arr[i] = data;
			break;
		}
	}
	if (i == length) arr[length] = data;
	length++;
}

void delete_node()
{
	int position;
	if (length == 0)
	{
		cout << "List is Empty!" << endl;
		return;
	}
	cout << "Enter the position of the Node to be deleted: ";
	cin >> position;
	if (position >= length)
	{
		cout << "Out of range!" << endl;
		return;
	}
	for (int i = position; i < length - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	length--;
}
void find()
{
	int data;
	if (length == 0)
	{
		cout << "List is Empty!" << endl;
		return;
	}
	cout << "Enter the data of the Node to be found: ";
	cin >> data;
	int i;
	for (i = 0; i < length; i++)
	{
		if (arr[i] == data) break;
	}
	if (i < length)
	{
		cout << "Node with data " << data << " is found at position " << i << endl;
	} else
	{
		cout << "Node with data " << data << " is not found" << endl;
	}
}

void print()
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << "-->";
	}
	cout << "NULL" << endl;
}
