#include "List.h"

template<class Type>
List<Type>::List()
{

	numberInList = 0;
	listSize = MAX;
	nextIndex = 0;
	Type t; // call default constructor of Type
	for (int i = 0; i < listSize; i++)
	{
		list[i] = t; // init element of list to t
	}
}

/*
template <class Type>
List<Type>& List<Type>::operator= (const List<Type>& right)
{
	if (this == &right)
		return *this;

	delete [] pList;
	deepCopy(right);

	return *this;

}*/

template<class Type>
void List<Type>::addMember(Type newMember)
{
	list[numberInList++] = newMember;
}

template<class Type>
Type List<Type>::getNext()
{
	Type t; // default t
	if (nextIndex == numberInList)
		return t;
	else
		return list[nextIndex++];
}

template<class Type>
bool List<Type>::getMember(Type &member)
{
	for(int i = 0; i < numberInList; i++)
	{
		if(list[i] == member)
		{
			member = list[i];
			return true;
		}
	}
	return false;
}

template<class Type>
int List<Type>::getNumber()
{
	return numberInList;
}

