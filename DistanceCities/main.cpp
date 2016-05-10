
#include <string>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
using namespace std;
#define n 10
int m[n][n], X, Y;

void generMat() { 
	for (int x = 0; x < n; x++) 
		for (int y = 0; y < n; y++) 
			m[x][y] = rand() % 100; 
}	//create data in array y[]

void printMat() { 
	for (int x = 0; x < n; x++) 
	{ 
		for (int y = 0; y < n; y++) 
			cout << m[x][y] << '\t'; 
		cout << endl; 
	} 
	cout << endl; 
}

void swap(int &a, int &b) { 
	int t = a; 
	a = b; 
	b = t; 
}

//The next two functions must be complete
void minInRow() { 
	int minInRowX = 999, t = 0; 
	for (int c = 0; c < n; c++) 
		if (m[X][c] < minInRowX) { 
			t = c; 
			minInRowX = m[X][c]; 
		} 
	swap(m[X][Y], m[X][t]); 
} //to complete
void maxInCol() { 
	int minInColY = 0, t = 0; 
	for (int r = 0; r < n; r++) 
		if (m[r][Y] > minInColY) { 
			t = r; 
			minInColY = m[r][Y]; 
		} 
	swap(m[X][Y], m[t][Y]); 
} //to complete 

																																						   
//n Cities located at <X,Y> coordinates, provided by this function:
int City[n][2];		//city <x,y> Coords
float Dist[n][n];	//adjacency matrix to show distances between <From, To> city_pair

void createMapCoords()
{
	for (int Ci = 0; Ci < n; Ci++) 
		for (int Co = 0; Co < 2; Co++) 
			City[Ci][Co] = rand() % 100;
	cout << "\nCity <x y> coords\n";
	for (int x = 0; x < n; x++) 
	{ 
		cout << x << ")   "; 
		for (int y = 0; y < 2; y++) 
			cout << City[x][y] << '\t'; 
			cout << endl; 
	} 
	cout << endl;
}

void plotMap() //draw the map with points representing the city locations
{
	cout << "\nM A P \n\n";
	string map[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			map[i][j] = "  "; //init map
	for (int i = 0; i < n; i++) 
		map[int(.1*City[i][0])][int(.1*City[i][1])] = ". ";  //place the n cities on the map
	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < n; j++) 
			cout << map[i][j]; cout << endl; 
	}
	cout << endl;
}

void answer()	//print the distances in this (adjacency matrix)
{
	plotMap();
	//initialize Dist[n][n] to zeros
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			Dist[i][j] = 0.;  
	
	/*  Wwrite your code here to calculate distances, and find the smallest distance, and print the found closest pair of cities
		Remember how to calculate the distance between two cities:
		if X1,Y1, and X2, Y2 are the coords of X, and Y cities: then Dist = sqrt((X2-X1)*(X2-X1) + (Y2-Y1)*(Y2-Y1))
	*/
	float distanceMin = 10000;
	int idmin = -1, jdmin = -1;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
		{
			// calculate distance between city i and city j
			Dist[i][j] = sqrt((City[j][0] - City[i][0]) * (City[j][0] - City[i][0]) + (City[j][1] - City[i][1]) * (City[j][1] - City[i][1]));
			if (i != j && Dist[i][j] < distanceMin) // if i = j that means same city, that won't count
			{
				distanceMin = Dist[i][j];
				idmin = i;
				jdmin = j;
			}
			
		}
	cout << "Smallest distance is: " << distanceMin << " between 2 cities (" << City[idmin][0] << "," << City[idmin][1] << ") and (";
	cout << City[jdmin][0] << "," << City[jdmin][1] << ")" << endl;
	cout << "\n<from,to> City Distances \tADJACENCY MATRIX\n\n";
	
	cout << " To>>\t"; 
	for (int j = 0; j < n; j++) 
		cout << j << '\t'; 
	cout << endl;
	
	cout << "\nFrom\n----\n";
	for (int i = 0; i < n; i++) { 
		cout << '\n' << i << ")\t";  
		for (int j = 0; j < n; j++) 
			cout << Dist[i][j] << '\t'; 
		cout << endl; 
	} 
	cout << endl;
}


int main()
{
	//Make sure it is correct:

	generMat();  printMat();
	cout << "Enter a position: "; 
	cin >> X >> Y;
	minInRow();  
	printMat();	//m[X][Y] becomes minInRow X
	maxInCol();  
	printMat();	//m[X][Y] becomes maxInCol Y

	//To complete
	srand(time(0));
	//Given <n> Cities located at <X,Y> coordinates, provided by this function:
	createMapCoords();  //this is a complete working code.

	//Find the closest two cities, and calculate the complexity big_O() of your algorithm: answer()
	answer();	// complete working code is given to you here, but  
				// You have to complete the distance calculation, and print the smallest one

	system("pause");
	return 0;
}


