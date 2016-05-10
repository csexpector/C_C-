/* 
 * File:   CoverFile.cc
 * Author: 
 * 
 * Created on March 16, 2016, 12:14 AM
 */

#include "CoverFile.h"
#include "Inventory.h"

CoverFile::CoverFile(string color, int size, int code, int qty, double unit_price):Inventory(code, qty, unit_price)
{
    this->color = color;
    this->size = size;
}

string CoverFile::getColor()
{
    return this->color;
}
int CoverFile::getSize()
{
    return this->size;
}

string CoverFile::getInventoryType(){
    return "Cover File";
}

