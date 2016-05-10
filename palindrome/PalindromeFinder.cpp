#include "PalindromeFinder.h"
#include <string>
#include <iostream>

using namespace std;

PalindromeFinder::PalindromeFinder()
{
	largestPalindromeFound = "";
}

string PalindromeFinder::toString()
{
	return "largest palindrome seen so far is \"" + this->getLargestPalindromeFound() + "\" with size " +
		to_string(this->getSizeOfLargestPalindromeFound());
}

string PalindromeFinder::getLargestPalindromeFound()
{
	return this->largestPalindromeFound;
}

int PalindromeFinder::getSizeOfLargestPalindromeFound()
{
	return largestPalindromeFound.length();
}

bool PalindromeFinder::isPalindrome(string stringToCheck)
{
	int low = 0;
	int high = stringToCheck.length() - 1;
	while (high > low)
	{
		if (stringToCheck[low++] != stringToCheck[high--]) return false;
	}
	
	// update largest palindrome so far
	if (largestPalindromeFound.length() < stringToCheck.length())
		largestPalindromeFound = stringToCheck;
	
	return true;
}

string PalindromeFinder::getLargestPalindrome(string* strList, int strSize)
{
	string largestString = "";
	int largestSize = 0;

	// for each string, check if it's palindrome. If yes then compare with the largest so far in the list and update it if needed
	for (int i = 0; i < strSize; i++)
	{
		string stringToCheck = strList[i];
		if (isPalindrome(stringToCheck) && largestSize < stringToCheck.length()) // palindrome and also largest in the list
		{
			// update
			largestSize = stringToCheck.length();
			largestString = stringToCheck;
		}
	}

	// update the global largest palindrome so far
	if (largestPalindromeFound.length() < largestString.length())
		largestPalindromeFound = largestString;

	return largestString;
}

void PalindromeFinder::truncateToLargestPalindrome(string& strToTruncate)
{
	int largestSize = 0;
	string largestString;
	// for each index i, we search largest palindrome starting from this index
	// compare the palindrome found with previous largest palindrome found and store the larger
	for (int i = 0; i < strToTruncate.length() - 1; i++)
	{
		string s = getLargestPalindromeFromIndex(strToTruncate, i);
		if (largestSize < s.length()) // compare 2 palindromes
		{
			// update the larger
			largestSize = s.length();
			largestString = s;
		}
	}

	strToTruncate = largestString;

	// compare with the largest palindrome so far and update it if needed
	if (largestPalindromeFound.length() < strToTruncate.length())
		largestPalindromeFound = strToTruncate;
}

string PalindromeFinder::getLargestPalindromeFromIndex(string str, const int low)
{
	int high = str.length() - 1;
	string stringToCheck = "";
	// starting with index low, we check backward with subtring from low to high
	// for each string, check if it is palindrome
	// if yes, this is the largest palindrome can be found starting from index low (because we search backward)
	while (high > 0)
	{
		stringToCheck = str.substr(low, high);
		if (isPalindrome(stringToCheck)) 
		{
			break; // found largest palindrome starting at index low, dont need to search anymore
		}
		else
		{
			high--; // continue searching backward
		} 
		
	}
	if (stringToCheck.length() == 1) stringToCheck = ""; // a string with size 1 is not considered palindrome!
	return stringToCheck;
}
