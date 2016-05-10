#include "PalindromeFinder.h"
#include <string>
#include <iostream>

int main()
{
	string* strings = new string[5];
	strings[0] = "Hello";
	strings[1] = "123454321";
	strings[2] = "fox for rof xof";
	strings[3] = "World";
	strings[4] = "i++ - ++i";

	// test to find largest palindrome
	PalindromeFinder* finder = new PalindromeFinder();
	finder->getLargestPalindrome(strings, 5);
	cout << finder->toString() << endl;


	// test to find largest truncation palindrome
	string s = "12213abcd dcba11111";
	cout << "original string is: " << s << endl;
	finder->truncateToLargestPalindrome(s);
	
	cout << "largest truncted string is " << s << endl;
}