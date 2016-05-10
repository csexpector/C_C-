#define NSHUFFLE 500

#define HEART   ((char)0x03)
#define DIAMOND ((char)0x04)
#define CLUB    ((char)0x05)
#define SPADE   ((char)0x06)

typedef struct strcard
{
	char suit[9];
	int value;
	struct strcard *pt;
} card;

typedef card* ptCard;





// draw a card from a deck to a hand
ptCard draw(ptCard* deck) ;

// shuffle a deck
void shuffle(ptCard* deck);

// get the last card in deck
ptCard last(ptCard deck);

// add 1 card to a hand (dealer hand or player hand)
void addToHand(ptCard* hand, ptCard newCard);

// get size of deck
int deck_size(ptCard deck);

// get internal card
ptCard internal(ptCard deck, int i);

// print deck
void showDeck(ptCard deck);

void showHand(ptCard hand);

// show card
void showCard(ptCard card);

// init 2 decks from file
void initDecks(ptCard *deck);

// count cards in hand
int count(ptCard hand);

// delete deck
void delDeck(ptCard* deck);

// delete hand
void delHand(ptCard* hand);
