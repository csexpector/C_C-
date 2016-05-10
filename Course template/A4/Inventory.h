/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
/* File:   Inventory.h                                           */
/* Author:                                                       */
/* Inventory class is the base class for all inventory           */
/* Items: Book, CoverFile, Pen                                                  */  
/* Created on March 15, 2016, 11:58 PM                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef INVENTORY_H
#define	INVENTORY_H
#include <string>


using namespace std;
class Inventory {
public:
    
    Inventory(int=0, int=0, double=0.0);
    virtual ~Inventory();
    int getCode();
    int getQty();
    double getUnitPrice();
    double getTotalPrice(); // returns total price for this inventory
    void print();
    virtual string getInventoryType()=0;
    
private:
    int code;         // Id for this inventory item
    int qty;        // number of qty available in stock
    double unit_price;   // per unit price for this inventory
};

#endif	/* INVENTORY_H */

