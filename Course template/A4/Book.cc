#include "Book.h"
#include "Inventory.h"

Book::Book(string t, string a, string i, int e, int y, int code, int qty, double unit_price):Inventory(code, qty, unit_price)
{
   title   = t;
   authors = a;
   isbn    = i;
   edition = e;
   year    = y;
}

string Book::getTitle()    { return title; }
string Book::getAuthors()  { return authors; }
string Book::getISBN()     { return isbn; }
int    Book::getEdition()  { return edition; }
int    Book::getYear()     { return year; }
string Book::getInventoryType(){
    return "Book";
}
