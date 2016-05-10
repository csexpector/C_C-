#ifndef PLAYER_H
#define PLAYER_H
class Player
{
	char* firstName;
	char* lastName;
	double  subscription;
	public:
	Player();
	Player(char*, char*, double);
	~Player();
	char* getFirstName(){ return firstName; }
	char* getLastName(){ return lastName; }
	double getSubscription(){ return subscription; }
};
#endif
