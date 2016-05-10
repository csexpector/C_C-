
#include<iostream>
#include<cstdlib>

using namespace std;

// Node
struct node
{
	int data;
	struct node *next;
}*head;


class SinglyLinkedList
{
public:
	node* createNode(int);
	void insert();
	void deleteNode();
	void find();
	void print();
	SinglyLinkedList()
	{
		head = NULL;
	}
};

// main function
int main()
{
	int choice, element, position, i;
	SinglyLinkedList LL;
	head = NULL;
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
			LL.insert();
			cout << endl;
			break;
		case 2:
			cout << "Delete a Node: " << endl;
			LL.deleteNode();
			break;
		case 3:
			cout << "Find a Node: " << endl;
			LL.find();
			cout << endl;
			break;
		case 4:
			cout << "Print all Nodes:  " << endl;
			LL.print();
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

// creates a node
node *SinglyLinkedList::createNode(int data)
{
	struct node *temp;
	temp = new(struct node);

	if (temp != NULL)
	{
		temp->data = data;
		temp->next = NULL;
		return temp;
	}
}

// Insert Node
void SinglyLinkedList::insert()
{
	int data;
	cout << "Enter the data of node: ";
	cin >> data;

	struct node *temp, *s;

	temp = createNode(data);

	if (head == NULL)
	{
		head = temp;
		head->next = NULL;
	}
	else
	{
		s = head;
		if (s->data > temp->data)
		{
			temp->next = head;
			head = temp;
		}
		else 
		{
			while (s->next != NULL)
			{			
				if (s->next->data > temp->data) break;
				s = s->next;
			}
			temp->next = s->next;
			s->next = temp;
		}
		
	}

	cout << "Node inserted" << endl;
}

// deletes a Node
void SinglyLinkedList::deleteNode()
{
	int position, i, counter = 0;
	if (head == NULL)
	{
		cout << "List is Empty!" << endl;
		return;
	}

	cout << "Enter the position of the Node to be deleted: ";
	cin >> position;

	struct node *temp, *ptr;
	temp = head;
	if (position < 0)
	{
		cout << "Invalid position" << endl;
		return;
	}
	if (position == 0)
	{
		head = temp->next;
	}
	else
	{
		while (counter < position)
		{
			counter++;
			ptr = temp;
			temp = temp->next;
			if (temp == NULL) break;
		}
		// after while loop, either counter = position or temp = NULL, let's check
		if (counter < position) // that means temp = NULL because of break command
		{
			cout << "Invalid position" << endl;
			return;
		}
		else
		{
			if (temp == NULL)
			{
				cout << "Invalid position" << endl;
				return;
			}
			else
			{
				ptr->next = temp->next;
				temp->next = NULL;
			}
		}
	}
	// free the memory
	free(temp);
	cout << "Node Deleted Successfully." << endl;
}

// Find a Node
void SinglyLinkedList::find()
{
	int data, position = 0;
	bool flag = false;

	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	cout << "Enter the data of the Node to be found: ";
	cin >> data;
	struct node *temp;
	temp = head;

	while (temp != NULL)
	{
		position++;
		if (temp->data == data)
		{
			flag = true;
			cout << "Node with data " << data << " is found at position " << position << endl;
		}
		temp = temp->next;
	}

	if (!flag)
		cout << "Node with data " << data << " not found in the list." << endl;
}


// Print all nodes
void SinglyLinkedList::print()
{
	struct node *temp;
	if (head == NULL)
	{
		cout << endl << "Empty List!" << endl;
		return;
	}

	temp = head;
	cout << endl << endl << "Elements of list are: " << endl;
	while (temp != NULL)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}


