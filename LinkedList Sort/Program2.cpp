#include <ctime>
#include <iostream>
#include<stdlib.h>
using namespace std;

int n = 60, arr[1000], key, samples = 40, sampleResults[100]; float scale = .5;

int execTime = 0; // complexity

int getSearchKey()
{
	cout << "Enter key : ";
	cin >> key;
	return (key);
}

int seqSearch()
{
	int i = 0;
	while (i<n && key != arr[i])
		i++;
	if (key == arr[i])
		return(i);
	return(-1);
}

int bSearchIteration(int first, int last)
{
	while (first<last)
	{
		int mid = (first + last) / 2;
		execTime++;
		if (arr[mid] == key)
		{
			return mid;
		}
		if (arr[mid]>key)
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
	}
	return -1;
}

int bSearchRecursion(int first, int last)
{
	int mid = (first + last) / 2;
	if (first > last)
		return -1;
	else
	{
		if (arr[mid] > key)
		{
			execTime++;
			bSearchRecursion(mid + 1, last);
		}
		else if (arr[mid] < key)
		{
			execTime++;
			bSearchRecursion(first, mid - 1);
		}
		else if (arr[mid] == key)
			return mid;
	}
}

void plot()
{
	for (int i = 0; i < n; i++)//repeat for n lines
	{
		for (int j = 0; j < arr[i] * scale; j++)
			cout << ' ';//skip the given spaces for that line
		cout << '*' << endl;//draw * and go to the next line
	}
}

void initArray()
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

void generArr()
{
	for (int x = 0; x < n; x++)
		arr[x] = rand() % n;
	cout << "Data has been generated successfully\n";
}

void printArr()
{
	for (int i = 0; i < n; i++)
		cout << i << ")\t" << arr[i] << endl;
}

void sortArr()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i]<arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
}

void plotSeqSearchTimes()
{
	for (int i = 0; i < samples; i++)
	{
		generArr();
		sampleResults[i] = seqSearch();
	}//analysis for seqSearch
	initArray();
	for (int i = 0; i < samples; i++)
		arr[i] = sampleResults[i];
	plot();
}

void plotBinSearchTimesIterative()
{
	for (int i = 0; i < samples; i++)
	{
		generArr();
		sortArr();
		sampleResults[i] = bSearchIteration(0, n);
	}//analysis for binary search iterative
	initArray();
	for (int i = 0; i < samples; i++)
		arr[i] = 5 * sampleResults[i];
	plot();

}

void plotBinSearchTimesRecursive()
{
	for (int i = 0; i < samples; i++)
	{
		generArr();
		sortArr();
		sampleResults[i] = bSearchRecursion(0, n);
	}//analysis for binary search recursive
	initArray();
	for (int i = 0; i < samples; i++)
		arr[i] = sampleResults[i];
	plot();

}
void menu()
{
	while (1)
	{
		int choice;
		cout << "STARTING MENU : \n";
		srand(time(0));
		cout << "\n 0-exit\n 1-seqSearch\n 2-bSearchIteration\n 3-bSearchRecursion\n 4-plot()\n 5-generArr()\n 6-printArr()\n";
		cout << " 7-plotSeqSearchTimes()\n 8-plotBinSearchTimesIterative()\n 9-plotBinSearchTimesRecursive()\n 10-getSearchKey()\n 11-sort the array.\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			key = getSearchKey();
			cout << seqSearch() << endl;
			break;
		case 2:
			key = getSearchKey();
			execTime = 0;
			cout << bSearchIteration(0, n);
			break;//for students to complete
		case 3:
			key = getSearchKey();
			execTime = 0;
			cout << bSearchRecursion(0, n);
			break;
		case 4:
			plot();
			break;
		case 5:
			generArr();
			break;
		case 6:
			printArr();
			break;
		case 7:
			cout << "Enter samples number\t";
			cin >> samples;
			plotSeqSearchTimes();
			break;
		case 8:
			cout << "Enter samples number\t";
			cin >> samples;
			plotBinSearchTimesIterative();
			break;//for students to complete
		case 9:
			cout << "Enter samples number\t";
			cin >> samples;
			plotBinSearchTimesRecursive();
			break;//for students to complete
		case 10:
			key = getSearchKey();
			break;
		case 11: sortArr();
			break; //SortArr()  must run before any BinSearch()  //IMPORTANT NOTE
		}
	}
}

int main()
{
	srand(time(0));
	menu();
	system("pause");
}


