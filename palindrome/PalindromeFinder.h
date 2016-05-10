#ifndef CSE250_FALL2015_STRINGWRAPPER_H
#define CSE250_FALL2015_STRINGWRAPPER_H

#include <string>
#include <iostream>

using namespace std;

class PalindromeFinder
{
private:
	string largestPalindromeFound;
public:
	PalindromeFinder();
	string toString();
	string getLargestPalindromeFound();
	int getSizeOfLargestPalindromeFound();

	bool isPalindrome(string);
	string getLargestPalindrome(string*, int);
	void truncateToLargestPalindrome(string&);
private:
	// return the largest palindrome (if any), starting from an index 
	string getLargestPalindromeFromIndex(string, const int);
};

#endif