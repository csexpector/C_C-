#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

class BookArray
{
  public:
    BookArray();
    void add(Inventory*);
    Inventory* getBook(int);
    int  getSize();
    virtual ~BookArray();
  private:
    int  size;
    Inventory *books[MAX_BOOKS];
};

#endif
