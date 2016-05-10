#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Inventory.h"

class Book:public Inventory{

  public:
    Book(string="", string="", string="", int=1, int=0, int=0, int=0, double=0.0);
    string  getTitle();
    string  getAuthors();
    string  getISBN();
    int     getEdition();
    int     getYear();
    string getInventoryType();

  private:
    string    title;
    string    authors;
    string    isbn;
    int       edition;
    int       year;
};

#endif

