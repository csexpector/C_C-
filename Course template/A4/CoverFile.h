/* 
 * File:   CoverFile.h
 * Author: 
 *
 * Created on March 16, 2016, 12:14 AM
 */

#ifndef COVERFILE_H
#define	COVERFILE_H
#include <string>
#include "Inventory.h"

using namespace std;

class CoverFile : public Inventory {
public:
    CoverFile(string="", int=0, int=0, int=0, double=0.0);
    string getColor();
    int getSize();
    string getInventoryType();

private:
    string color;
    int size;
    
};

#endif	/* COVERFILE_H */

