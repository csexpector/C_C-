/* 
 * File:   BaseballBat.h
 * Author: 
 *
 * Created on March 16, 2016, 12:46 AM
 */

#ifndef BASEBALLBAT_H
#define	BASEBALLBAT_H

#include "Inventory.h"
#include <iostream>
using namespace std;

class BaseballBat : public Inventory{
public:
    BaseballBat(string="", string="", int=0, int=0, int=0, double=0.0);
    string getColor();
    string getBuilt();
    int getSize();
    string getInventoryType();
private:
    int size;
    string color;
    string built;       // aluminium or wood
};

#endif	/* BASEBALLBAT_H */

