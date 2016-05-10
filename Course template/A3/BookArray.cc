#include <iostream>
#include <string>
using namespace std;

#include "BookArray.h"

BookArray::BookArray() 
{ 
  size = 0;
}
BookArray::~BookArray(){
    for(int i=0; i<size; ++i){
        delete books[i];
    }
}
int   BookArray::getSize()        { return size; }
Inventory*  BookArray::getBook(int i)   { return books[i]; }

void BookArray::add(Inventory* book)
{
  if (size == MAX_BOOKS)
    return;

  books[size] = book;
  size++;
}

