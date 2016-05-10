#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

typedef struct strCard
{
	int rank;		// rank of card
	string suit;	// suit of card
} Card;

string cardToString(Card card)
{
	string str;
	if (card.rank <= 10)
	{
		
		stringstream ss;
		ss << card.rank; // convert int to string
		str = ss.str();
	}
	else
	{
		switch (card.rank)
		{
			case 11: str = "Jack"; break;
			case 12: str = "Queen"; break;
			case 13: str = "King"; break;
			case 14: str = "Ace"; break;
		}
	}
	str += " of " + card.suit;
	return str;
}

Card makeCard(int rank, string suit)
{
	Card card;
	card.rank = rank; // set card's rank
	card.suit = suit; // set card's suit
	return card;
}

int getRandRank()
{
	// get random number from 2 to 14
	int rank = 2 + rand() % 13;
	return rank;
}
string getRandSuit()
{
	// get random number from 0 to 3
	int s = rand() % 4;
	// convert s to suit
	string suit;
	switch (s)
	{
		case 0: suit = "Clubs"; break;
		case 1: suit = "Diamonds"; break;
		case 2: suit = "Spades"; break;
		case 3: suit = "Hearts"; break;
		default: suit = "Hearts"; // that will never happen but Xcode requires default in switch		
	}
	return suit;
}
bool isEqual(Card c1, Card c2)
{
	return c1.rank == c2.rank;
}
bool isLess(Card c1, Card c2)
{
	return c1.rank < c2.rank;
}
bool isGreater(Card c1, Card c2)
{
	return c1.rank > c2.rank;
}
int main(int argc, char** argv) {
	// init srand to generate random number
	srand(time(NULL));
	rand();
	
	// set player's names
	string player1 = "Curly";
	string player2 = "Harry";
	// init scores
	int score1 = 0, score2 = 0;
	// init round
	int round = 1;
	// to get answer yes or no
	char ans;
	cout << "Welcome to ESPN's coverage of the world champion High-card tournament finals!" << endl 
		 << "It's a match between Larry and Curly!" << endl << endl;
	while (true)
	{
		cout << "They're starting round " << round++ << "." << endl;
		cout << "The players are shuffling... " << endl;
		// shuffle cards
		Card c1 = makeCard(getRandRank(), getRandSuit());
		Card c2 = makeCard(getRandRank(), getRandSuit());
		// compare cards
		if (isEqual(c1, c2))
		{
			cout << "I didn't see that coming! " << endl;
			cout << player1 << " drew a " << cardToString(c1) << " to match "
				 << player2 << "'s " << cardToString(c2) << endl;
			cout << "It's a DRAW!" << endl;
			
			
		}
		else if (isLess(c1, c2))
		{
			cout << "Isn't this exciting! " << endl;
			cout << player2 << "'s " << cardToString(c2) << " beats " << player1 << "'s " << cardToString(c1) << endl;
			score2++;
		}

		else if (isGreater(c1, c2))
		{
			cout << "Look at that!" << endl;
			cout << player1 << "'s " << cardToString(c1) << " beats " << player2 << "'s " << cardToString(c2) << endl;
			score1++;
		}	
		// Show scores
		cout << "The score is ..." << endl;
		cout << player1 << ": " << score1 << ", " << player2 << ": " << score2 << endl;
		// Ask user to continue or not
		cout << "Should the 2 players go again (y/n)? ";
		cin >> ans;
		fflush(stdin); // remove '\n'
		
		// user doesn't want to continue so break out of while
		if (ans == 'n') break;
	}
	cout << "Well that's all we have time for tonight. " << endl << "For ESPN, this is Bob Jarvis, reporting live! " << endl;
	return 0;
}
