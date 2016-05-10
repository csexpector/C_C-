#include "cards.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



int count(ptCard hand)
{
	ptCard p = hand;
	int sum = 0, i;
	int nAces = 0;
	while (p != NULL)
	{
		int v = p->value;
		if (v > 10) v = 10;
		if (v == 1) nAces++;
		sum += v;
		p = p->pt;
	}
	// return the max sum as long as it less than 31
	for (i = 0; i < nAces; i++)
	{
		// ace can be counted as 11
		if ((sum + 10) < 31) sum += 10;
	}
	return sum;
}
void addToHand(ptCard* hand, ptCard newCard)
{
	if (*hand == NULL)
	{
		*hand = newCard;
	}
	else
	{
		ptCard l = last(*hand);
		l->pt = newCard;
		newCard->pt = NULL;
	}
}
// draw a card from a deck
ptCard draw(ptCard* deck)
{
	if (*deck == NULL) return NULL;	
	else
	{
		ptCard p = *deck;
		*deck = (*deck)->pt;
		p->pt = NULL;
		return p;
	}
}
// shuffle a deck
void shuffle(ptCard* deck)
{
	int i;
	time_t t;
	srand((unsigned) time(&t));
	initDecks(deck);
	int n = deck_size(*deck);
	for (i = 0; i < NSHUFFLE; i++)
	{
		int middle = rand() % (n - 2) + 1;
		ptCard m = internal(*deck, middle);
		// shuffle
		ptCard p = (*deck)->pt;
		(*deck)->pt = m->pt;
		m->pt = *deck;
		*deck = p;
	}
	
}

// delete deck
void delDeck(ptCard* deck)
{
	ptCard p = *deck;
	while (p != NULL)
	{
		ptCard q = p;
		p = p->pt;
		free(q);
	}
	*deck = NULL;
}
// delete hand
void delHand(ptCard* hand)
{
	ptCard p = *hand;
	while (p != NULL)
	{
		ptCard q = p;
		p = p->pt;
		free(q);
	}
	*hand = NULL;
}
// get the last card in deck
ptCard last(ptCard deck)
{
	ptCard p = deck;
	while (p->pt != NULL) p = p->pt;
	return p;
}
// get internal card
ptCard internal(ptCard deck, int n)
{
	ptCard p = deck;
	int i = 0;
	while (i < n)
	{
		p = p->pt;
		i++;
	}
	return p;
}

// get size of deck
int deck_size(ptCard deck)
{
	ptCard p = deck;
	int i = 1;
	while (p != NULL) 
	{
		p = p->pt;
		i++;
	}
	return i-1;
}

// print deck
void showDeck(ptCard deck)
{
	while (deck != NULL)
	{
		showCard(deck);
		deck = deck->pt;
	}
}

// print deck
void showHand(ptCard hand)
{
	while (hand != NULL)
	{
		showCard(hand);
		hand = hand->pt;
	}
	printf("\n");
}

// show card
void showCard(ptCard card)
{
	if (card->value > 1 && card->value <= 10)
		printf("%d", card->value);
	else if (card->value == 1)
		printf("%c", 'A');
	else if (card->value == 11)
		printf("%c", 'J');
	else if (card->value == 12)
		printf("%c", 'Q');
	else if (card->value == 13)
		printf("%c", 'K');
	if (strcmp(card->suit, "diamonds") == 0)
	{
		printf("%c ", DIAMOND);
	}
	else if (strcmp(card->suit, "clubs") == 0)
	{
		printf("%c ", CLUB);
	}
	else if (strcmp(card->suit, "hearts") == 0)
	{
		printf("%c ", HEART);
	}
	else if (strcmp(card->suit, "spades") == 0)
	{
		printf("%c ", SPADE);
	}
}

// init 2 decks from file
void initDecks(ptCard* deck)
{
	FILE* f = fopen("deck_and_suits.txt", "r");
	*deck = (ptCard)malloc(sizeof(card));
	fscanf(f, "%d", &((*deck)->value));
	fscanf(f, "%s", (*deck)->suit);
	(*deck)->pt = NULL;
	ptCard p = *deck;
	while (!feof(f))
	{
		p->pt = (ptCard)malloc(sizeof(card));
		p = p->pt;
		
		fscanf(f, "%d", &(p->value));
		fscanf(f, "%s", p->suit);
		
		p->pt = NULL;
	}
	fclose(f);
}

