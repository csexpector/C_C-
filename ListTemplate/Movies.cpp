#include "List.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

typedef struct Movie
{
	int MPAC;
	int year;
	int runtime;
	int checkedIn;
	int checkedOut;
	string title;
	Movie() : MPAC(0) {};
	inline bool operator==(int iMPAC)
    {
        if (MPAC == iMPAC) return true;
        else return false;
    }
} Movie;

List<Movie> getData();
void displayList(List<Movie> lstMovies);
void findMovies(List<Movie> lstMovies);
int main()
{
	List<Movie> lstMovies = getData();
	displayList(lstMovies);
	findMovies(lstMovies);
	return 0;
}
void findMovies(List<Movie> lstMovies)
{
	int MPAC;
	while (true)
	{
		cout << "Enter a movie MPAC (0 to exit) to locate: ";

		cin >> MPAC;

		if (MPAC == 0) break;
		bool found = false;
		for (int i = 0; i < lstMovies.getNumber(); i++)
		{
			Movie m = lstMovies.getNext();
			if (m == MPAC)
			{
				cout << setw(10) << "MPAC" << setw(30) << "Title" << setw(6) 
		 			 << "Year" << setw(10) << "RunTime" << setw(4) << "In" << setw(4) << "Out" << endl;
		 		cout << "-------------------------------------------------------------------" << endl;
				cout << setw(10) << m.MPAC << setw(30) << m.title << setw(6) << m.year << setw(10) << m.runtime
			 		 << setw(4) << m.checkedIn << setw(4) << m.checkedOut << endl;
			 	found = true;
				break;
			}
		}
		if (!found)	cout << "Movie not found!" << endl;
	}
}
void displayList(List<Movie> lstMovies)
{
	float averageRuntime = 0;
	int totalCheckIn = 0, totalCheckOut = 0;
	cout << "The Webster Movie Store list includes:" << endl;
	cout << setw(10) << "MPAC" << setw(30) << "Title" << setw(6) 
		 << "Year" << setw(10) << "RunTime" << setw(4) << "In" << setw(4) << "Out" << endl;
	cout << "-------------------------------------------------------------------" << endl;

	for (int i = 0; i < lstMovies.getNumber(); i++)
	{
		Movie m = lstMovies.getNext();
		cout << setw(10) << m.MPAC << setw(30) << m.title << setw(6) << m.year << setw(10) << m.runtime
			 << setw(4) << m.checkedIn << setw(4) << m.checkedOut << endl;
		averageRuntime += m.runtime;
		totalCheckIn += m.checkedIn;
		totalCheckOut += m.checkedOut;
	}

	cout << "The average runtime of " << lstMovies.getNumber() << " movies is: " << averageRuntime / lstMovies.getNumber() << endl;
	cout << "There are " << totalCheckIn << " movies checked in" << endl;
	cout << "There are " << totalCheckOut << " movies checked out" << endl;
}
List<Movie> getData()
{
	List<Movie> lstMovies;
	ifstream fin;
	fin.open("Movies.csv");
	if (!fin)
	{
		cout << "File Movies.csv not found!" << endl;
		exit(99);
	}
	while (!fin.eof())
	{
		Movie m;
		string s, MPAC, year, runtime, checkedIn, checkedOut, title;
		getline(fin, s);

		std::stringstream ss(s);

        if (s == "") break;

        std::getline(ss, MPAC, ',');
        stringstream(MPAC) >> m.MPAC; //cout << "MPAC: " << MPAC;

		std::getline(ss, year, ','); //cout << "Year: " << year;
        stringstream(year) >> m.year;

        std::getline(ss, runtime, ','); //cout << "RunTime: " << runtime;
        stringstream(runtime) >> m.runtime;

        std::getline(ss, checkedIn, ','); //cout << "checkedIn" << checkedIn;
        stringstream(checkedIn) >> m.checkedIn;

        std::getline(ss, checkedOut, ',');
        stringstream(checkedOut) >> m.checkedOut; //cout << "checkedOut" << checkedOut;

        std::getline(ss, title, '\r'); //cout << "Title: " << title;
        m.title = title;

        lstMovies.addMember(m);

	}

	fin.close();
	return lstMovies;
}