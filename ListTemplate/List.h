#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
using namespace std;

#define MAX 100

template<class Type>
class List
{
	private:
		Type list[MAX];
		int numberInList;
		int listSize;
		int nextIndex;
	public:
		List()
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
		//List(int);
		//List(const List<Type>&);
		//~List();
		void addMember(Type newMember)
		{
			list[numberInList++] = newMember;
		}
		bool getMember(Type& member)
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
		Type getNext()
		{
			Type t;
			if (nextIndex == numberInList)
				return t;
			else
				return list[nextIndex++];
		}
		int getNumber()
		{
			return numberInList;
		}
};

#endif
