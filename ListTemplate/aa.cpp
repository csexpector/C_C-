#include "List.h"
template<class DT>
List<DT>::List()
{
	pList = new DT [100];
	numberInList = 0;
	listSize = 100;
	nextIndex = 0;
}

template <class DT>
List<DT>::List(int n)
{
	pList = new DT [n];
	numberInList = 0;
	listSize = n;
	nextIndex = 0;
}

template <class DT>
List<DT>& List<DT>::operator = (const List<DT>& right)
{
	if (this == &right)
		return *this;

	delete [] pList;
	deepCopy(right);

	return *this;

}

template<class DT>
List<DT>::~List()
{
	cout<<"The destructor is running"<<endl;
	delete [] pList;
}

template<class DT>
void List<DT>::addMember(DT& member)
{
	pList[numberInList]=member;
	numberInList++;
}

template<class DT>
DT List<DT>::getNext()
{
	if (nextIndex>=numberInList)
		nextIndex=0;
	return pList[nextIndex++];
}

template<class DT>
bool List<DT>::getMember(DT& member)
{
	bool found = false;
	for(int i=0; i<numberInList; i++)
	{
		if(pList[i]==member)
		{
			member=pList[i];
			found=true;
		}
	}
	return found;
}

template<class DT>
int List<DT>::getNumOfMembers()
{
	return numberInList;
}

