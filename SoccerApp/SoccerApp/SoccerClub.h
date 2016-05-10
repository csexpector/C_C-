#ifndef SOCCER_H
#define SOCCER_H
#include "Link.h"   // <--- have to add this to use class Link
class SoccerClub
{
	Link* pPlayers;
public:
	SoccerClub();
	~SoccerClub();
	void AddPlayer();
	void DeletePlayer();
	void PrintPlayersForward();
	void PrintPlayersReverse();
};
#endif