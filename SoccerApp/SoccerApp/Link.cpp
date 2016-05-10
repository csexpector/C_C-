#include "stdafx.h"
#include "Link.h"

// Constructor of Link
Link::Link(Link* prev, Link* next, Player* p)
{
	pPrev = prev;
	pNext = next;
	pPlayer = p;
}
// destructor of Link
Link::~Link()
{
	if (pPrev != nullptr) delete pPrev;
	if (pNext != nullptr) delete pNext;
	delete pPlayer;
	pPlayer = nullptr;
}
