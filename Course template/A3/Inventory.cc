/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* File:   Inventory.cc                                          */
/* Author:                                                       */
/* Implementation of Inventory class                                                              */   
/* Created on March 15, 2016, 11:58 PM                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <iomanip>
#include "Inventory.h"

using namespace std;

Inventory::Inventory(int code, int qty, double unit_price) { 
    this->code = code;
    this->qty = qty;
    this->unit_price = unit_price;
}

Inventory::~Inventory(){
    
}
int Inventory::getCode(){
    return this->code;
}
int Inventory::getQty(){
    return this->qty;
}
double Inventory::getUnitPrice(){
    return this->unit_price;
}
double Inventory::getTotalPrice(){
    return this->getUnitPrice() * this->getQty(); 
}

void Inventory::print()
{
    cout << setw (15) << left <<this->getInventoryType() << " "
            <<setw(10) << right << this->getCode() << " "
            << setw(10) << right << this->getQty() <<  " "
            << setw(10) << right << setprecision (2) << fixed << this->getUnitPrice() << " "
            << setw(10) << right << setprecision(2) << fixed << this->getTotalPrice() << endl;
 }