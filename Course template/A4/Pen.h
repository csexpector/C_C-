/* 
 * File:   Pen.h
 * Author: 
 *
 * Created on March 16, 2016, 12:20 AM
 */

#ifndef PEN_H
#define	PEN_H

#include "Inventory.h"
#include <string>

using namespace std;

class Pen : public Inventory {

public:
    Pen(string="", string="", int=0, int=0, double=0.0);
    string getInkColor();
    string getMake();
    string getInventoryType();

private:
    string ink_color;
    string make;
};

#endif	/* PEN_H */

