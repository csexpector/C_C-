#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define NAMELEN 20
#define NSUITS 4
#define NRANKS 13
#define NCARDS 52

void printMenu();
void readUnshuffledCards(char unshuffledCards[NSUITS][NRANKS][NAMELEN]);
void printUnshuffledCards(char unshuffledCards[NSUITS][NRANKS][NAMELEN]);
void shuffleCards(char unshuffledCards[NSUITS][NRANKS][NAMELEN], char shuffledCards[NCARDS][NAMELEN]);
void swap (int *a, int *b);
void randomizeCardsIndex ( int cardIndex[NCARDS] );
void printShuffledCards(char shuffledCards[NCARDS][NAMELEN]);
void printShuffledCardsToFile(char shuffledCards[NCARDS][NAMELEN]);
int main()
{
	int choice;
	char unshuffledCards [NSUITS][NRANKS][NAMELEN];
	while (true)
	{	

		printMenu();
		cin >> choice;
		switch (choice)
		{
			case 1: 
				cout << "Reading unshuffled cards from file ... "; 
				
				readUnshuffledCards(unshuffledCards);
				cout << "Finish!" << endl << "Here are unshuffled cards: " << endl;
				printUnshuffledCards(unshuffledCards);
				cout << endl << endl << endl;
				break;
			case 2: 
				cout << "Shuffle cards ... "; 
				char shuffledCards [NCARDS][NAMELEN];
				shuffleCards(unshuffledCards, shuffledCards);
				cout << "Finish!" << endl << "Here are shuffled cards: " << endl;
				printShuffledCards(shuffledCards);
				cout << "Print to output.txt ... ";
				printShuffledCardsToFile(shuffledCards);
				cout << "Done!" << endl;
				break;
			case 3: cout << "Bye!" << endl; return 0;
			default: cout << "Unkown choice!" << endl; break;
		}
	}
	return 0;

}

void printMenu()
{
	cout << "Choose your action:" << endl;
	cout << "1. Read unshuffled cards from input.txt." << endl;
	cout << "2. Shuffle the cards and print to output.txt." << endl;
	cout << "3. Quit." << endl;
	cout << "Your choice: ";
}

void readUnshuffledCards(char unshuffledCards[NSUITS][NRANKS][NAMELEN])
{
	ifstream cardsFile;
	cardsFile.open("input.txt");
	int i = 0;
	char line[256];
	while (cardsFile.getline(line, 256))
	{	
		//cout << "DEBUG line = " << line << endl;
		int l = 0;
		for (int j = 0; j < NRANKS; j++)
		{
			int k = 0;

			while (line[l] != ' ') // read rank
			{
				//cout << line[l];
				unshuffledCards[i][j][k++] = line[l++];
			}
			unshuffledCards[i][j][k++] = line[l++]; // blank character

			while (line[l] != ' ' && line[l] != '\0') // read suit
			{
				//cout << line[l];
				unshuffledCards[i][j][k++] = line[l++];
			}

			unshuffledCards[i][j][k] = '\0'; // terminate the string
			
			//cout << "DEBUG i = " << i << " j = " << j << " k = " << k << " cards: ";
			//k = 0;
			//while (unshuffledCards[i][j][k] != '\0') cout << unshuffledCards[i][j][k++];
			//cout << endl;
			l++; // by pass blank character
		}
		i++;
	}
	cardsFile.close();
}

void printUnshuffledCards(char unshuffledCards[NSUITS][NRANKS][NAMELEN])
{
	for (int i = 0; i < NSUITS; i++)
	{
		for (int j = 0; j < NRANKS; j++)
		{
			int k = 0;
			while (unshuffledCards[i][j][k] != '\0')
			{
				cout << unshuffledCards[i][j][k++];
			}
			cout << " ";
		}
	}
}

void printShuffledCards(char shuffledCards[NCARDS][NAMELEN])
{
	for (int i = 0; i < NCARDS; i++)
	{
		int k = 0;
		while (shuffledCards[i][k] != '\0')
		{
			cout << shuffledCards[i][k];
			k++;
		}
		cout << " ";
	}
	cout << endl;
}

void printShuffledCardsToFile(char shuffledCards[NCARDS][NAMELEN])
{
	ofstream ofile;
	ofile.open("output.txt");
	for (int i = 0; i < NCARDS; i++)
	{
		int k = 0;
		while (shuffledCards[i][k] != '\0')
		{
			ofile << shuffledCards[i][k];
			k++;
		}
		ofile << " ";
	}
	ofile << endl;
	ofile.close();
}


void shuffleCards(char unshuffledCards[NSUITS][NRANKS][NAMELEN], char shuffledCards[NCARDS][NAMELEN])
{
	int cardIndex[NCARDS];
	randomizeCardsIndex(cardIndex);
	//cout << "Here?" << endl;
	for (int i = 0; i < NCARDS; i++)
	{
		int randomIndex = cardIndex[i];
		int iindex = randomIndex / NRANKS;
		int jindex = randomIndex - NRANKS * iindex;
		//cout << "i: " << i << " randomIndex: " << randomIndex << " iindex: " << iindex << " jindex: " << jindex << endl;
		//cout << "char: " << readUnshuffledCards[iindex][jindex][k] << endl;
		for (int k = 0; k < NAMELEN; k++)
		{
			shuffledCards[i][k] = unshuffledCards[iindex][jindex][k];
		}
	}
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 

void randomizeCardsIndex ( int cardIndex[NCARDS] )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    for (int i = 0; i < NCARDS; i++)
    	cardIndex[i] = i;
    srand ( time(NULL) );
 	int n = NCARDS;
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
        swap(&cardIndex[i], &cardIndex[j]);
    }

    
}