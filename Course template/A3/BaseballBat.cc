/* 
 * File:   BaseballBat.cc
 * Author: 
 * 
 * Created on March 16, 2016, 12:46 AM
 */

#include "BaseballBat.h"

BaseballBat::BaseballBat(string color, string built, int size, int code, int qty, double unit_price):Inventory(code, qty, unit_price) {
    this->color = color;
    this->built = built;
    this->size = size;
}

string BaseballBat::getColor(){
    return this->color;
}
string BaseballBat::getBuilt(){
    return this->built;
}
int BaseballBat::getSize(){
    return this->size;
}
string BaseballBat::getInventoryType(){
    return "Baseball Bat";
}

