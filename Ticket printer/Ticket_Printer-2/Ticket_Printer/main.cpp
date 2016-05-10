#include <iostream>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Performance.h"
#include "Ticket.h"
#include "Ticket_Book.h"
#include <fstream>

using namespace std;



int main()
{
	string fname;
	cout << "Name for input file? ";
	cin >> fname;
	//fname = "C:\\tampa_venues.txt";
	fflush(stdin); // flush the '\n' when user presses enter
	// open file fname
	ifstream venueFile(fname);
	// Test if there is fname or not
	if (!venueFile.is_open())
	{
		cout << "Cannot open " << fname << endl;
		cin.get();
		return 0;
	}
	string venue_name, venue_addr_line1, venue_addr_line2, venue_addr_line3, strzip;
	int zip;
	Venue *venues[100];
	int nVenues = 0;
	// Read file conent to array vanues
	while (true)
	{
		if (!getline(venueFile, venue_name))
		{
			break;
		}
		getline(venueFile, venue_addr_line1);
		getline(venueFile, venue_addr_line2);
		getline(venueFile, venue_addr_line3);
		getline(venueFile, strzip);
		zip = stoi(strzip);
		Address *addr = new Address(venue_addr_line1, venue_addr_line2, venue_addr_line3, zip);
		Venue* venue = new Venue(venue_name, *addr);
		venues[nVenues++] = venue;
		// maximum vanues is 100
		if (nVenues >= 100) break;
	}
	cout << nVenues << " venues read from file" << endl << endl;
	cout << " *** Venues before sort ***" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < nVenues; i++)
	{
		venues[i]->Display();
		cout << endl;
	}
	cout << " *** Venues after sort ***" << endl;
	cout << "--------------------------" << endl;
	// sort
	for (int i = 0; i < nVenues - 1; i++)
	{
		for (int j = i + 1; j < nVenues; j++)
		{
			if (*venues[j] < *venues[i]) // call operator< of class Venue
			{
				// swap 2 pointers, move smaller one to the head
				Venue * v = venues[i];
				venues[i] = venues[j];
				venues[j] = v;
			}
		}
	}
	for (int i = 0; i < nVenues; i++)
	{
		venues[i]->Display();
		cout << endl;
	}
    cin.get();   // Hold the window open
    return 0;
}


