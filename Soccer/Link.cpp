#include "Link.h"
Link::Link(Link* prev, Link* next, Player* p)
{
	pPrev = prev;
	pNext = next;
	pPlayer = p;
}
Link::~Link()
{
	if (pPrev != nullptr) delete pPrev;
	if (pNext != nullptr) delete pNext;
	delete pPlayer;
	pPlayer = nullptr;
}
