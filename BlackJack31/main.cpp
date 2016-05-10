#include <stdio.h>
#include "cards.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MINBET 20
#define MAXBET 200

void gameLoose(ptCard dealerHand, int &pp, int bet, int dealerPoint);
void gameDraw(ptCard dealerHand, int dealerPoint);
void gameWin(ptCard dealerHand, int &pp, int bet, int dealerPoint);
void askBet(int &bet, const int accept);
int gameOver;

int main(int argc, char** argv) 
{
	int c, bet, totalBet, round = 0;
	
	ptCard playerHand = NULL, dealerHand = NULL;
	
	int playerMoney = 1000;
	
	int playerPoint, dealerPoint;
	
	ptCard deck = NULL;
	shuffle(&deck);
	
	while(1) // each loop is a round
	{
		int s = deck_size(deck);
		if (s < 30) // if deck size less than 30 then suffle deck
		{
			delDeck(&deck);
			shuffle(&deck);
			
		}
		delHand(&playerHand);
		delHand(&dealerHand);
		
		gameOver = 0;
		printf("Round %d -- Your money: %d -- Total cards in deck: %d\n", ++round, playerMoney, deck_size(deck));
		totalBet = 0;
		//playerHand = NULL;
		//dealerHand = NULL;
		// ask for bet
		askBet(bet, playerMoney);
		
		totalBet += bet;
		// deal player first
		ptCard p = draw(&deck);
		addToHand(&playerHand, p);
		printf("1st player's card: ");
		showCard(p);
		printf("\n");
		// then deal dealer
		p = draw(&deck);
		addToHand(&dealerHand, p);
		// 1st dealer's card is shown
		printf("1st dealer's card: ");
		showCard(p);
		printf("\n");
		// ask player to hit or stand
		printf("Hit or stand? (1-hit, 2-stand): ");
		scanf("%d", &c);
		while (c == 1)
		{
			askBet(bet, playerMoney);
			
			totalBet += bet;
			printf("Total bet: %d\n", totalBet);
			
			p = draw(&deck);
			addToHand(&playerHand, p);
			p = draw(&deck);
			addToHand(&dealerHand, p);
			
			playerPoint = count(playerHand);
			dealerPoint = count(dealerHand);
			
			printf("Player's hand: \n"); showHand(playerHand);
			printf("Player point: %d\n", playerPoint);
			if (playerPoint > 31 && dealerPoint <= 31)
			{				
				gameLoose(dealerHand, playerMoney, totalBet, dealerPoint);
				break;
			}
			if (playerPoint <=31 && dealerPoint > 31)
			{
				gameWin(dealerHand, playerMoney, totalBet, dealerPoint);
				break;
			}
			if (playerPoint >31 && dealerPoint > 31)
			{
				gameDraw(dealerHand, dealerPoint);
				break;
			}
			if (playerPoint == 14)
			{
				 
				printf("You can stand at 14, hit or stand? (1-hit, 2-stand): ");
				scanf("%d", &c);
				if (c == 2)
				{
					// TODO: check if dealer is also 14 then it is game draw
				
					// if not, then dealer has to hit until 31
					while (dealerPoint <= 31)
					{
						p = draw(&deck);
						addToHand(&dealerHand, p);
						dealerPoint = count(dealerHand);
					}
					printf("Dealer's hand: ");	showHand(dealerHand);
					printf("Dealer point: %d\n", dealerPoint);
					printf("Player point: %d\n", playerPoint);
					if (dealerPoint == 31)
					{
						gameLoose(dealerHand, playerMoney, totalBet, dealerPoint);
					}
					else
					{
						gameWin(dealerHand, playerMoney, totalBet, dealerPoint);
					}
				}
				else
				{
					printf("You choose to hit\n");
				}
			}
			else
			{
				// ask player to hit or stand
				printf("Hit or stand? (1-hit, 2-stand): ");
				scanf("%d", &c);
			}
		} // end choice = 1
		
		// player choose to stand or game is over, so need to check
		if (!gameOver)
		{
			// dealer has to hit until at least 27
			while (dealerPoint <= 27)
			{
				p = draw(&deck);
				addToHand(&dealerHand, p);
				dealerPoint = count(dealerHand);
			}
			if (dealerPoint > 31)
			{
				gameWin(dealerHand, playerMoney, totalBet, dealerPoint);
			}
			else if (playerPoint < dealerPoint)
			{
				gameLoose(dealerHand, playerMoney, totalBet, dealerPoint);
			}
			else if (playerPoint > dealerPoint)
			{
				gameWin(dealerHand, playerMoney, totalBet, dealerPoint);
			}
			else
			{
				gameDraw(dealerHand, dealerPoint);
			}
		}
		printf("Continue? (1-yes, 2-no): ");
		scanf("%d", &c);
		if (c == 2) break;
	}
	return 0;
}

void gameLoose(ptCard dealerHand, int &pp, int bet, int dealerPoint)
{
	printf("Dealer's hand: \n");
	showHand(dealerHand);
	printf("Dealer point: %d\n", dealerPoint);
	printf("You lost!\n");
	pp -= bet;
	gameOver = 1;
}

void gameDraw(ptCard dealerHand, int dealerPoint)
{
	printf("Dealer's hand: \n");
	showHand(dealerHand);
	printf("Dealer point: %d\n", dealerPoint);
	printf("Game draw!\n");
	gameOver = 1;
}
void gameWin(ptCard dealerHand, int &pp, int bet, int dealerPoint)
{
	printf("Dealer's hand: \n");
	showHand(dealerHand);
	printf("Dealer point: %d\n", dealerPoint);
	printf("You won!\n");
	pp += bet;
	gameOver = 1;
}
void askBet(int &bet, const int accept)
{
	do
	{
		printf("Bet amount: ");
		scanf("%d", &bet);
		if (bet < MINBET || bet > MAXBET || bet > accept)
		{
			printf("Bet has to be in [%d, %d], and not exceed %d\n", MINBET, MAXBET, accept);
		}
	} while (bet < MINBET || bet > MAXBET || bet > accept);
}
