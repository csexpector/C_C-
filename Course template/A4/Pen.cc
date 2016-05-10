/* 
 * File:   Pen.cc
 * Author: 
 * 
 * Created on March 16, 2016, 12:20 AM
 */

#include "Pen.h"
#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

Pen::Pen(string ink_color, string make, int code, int qty, double unit_price):Inventory (code, qty, unit_price)
{
    this->ink_color = ink_color;
    this->make = make;
}

string Pen::getInkColor(){
    return this->ink_color;
}
string Pen::getMake(){
    return this->make;
}

string Pen::getInventoryType(){
    return "Pen";
}