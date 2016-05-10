#include "stdafx.h"
#ifndef LINK_H
#define LINK_H 
#include "Player.h"  // <--- have to add this to use class Player
struct Link
{
	Player* pPlayer;
	Link* pNext;
	Link* pPrev;
	Link()
	{
		pPrev = nullptr;
		pNext = nullptr;
	}
	Link(Link*, Link*, Player*);
	~Link();
};
#endif

