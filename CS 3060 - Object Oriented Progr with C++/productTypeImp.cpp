#include <iostream>
#include <string>
#include <iomanip>
#include "productType.h"

using namespace std;

productType::productType(){
    productName = "";
    id = "";
    manufacturer = "";
    quantitiesInStock = 0;
    price = 0.0;
    discount = 0.0;
}
productType::productType(int x, double y, double z){
    productName = "";
    id = "";
    manufacturer = "";
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;
    
    if(y >= 0.0)
        price = y;
    else 
        price = 0.0;
    
    if(z >= 0.0)
        discount = z;
    else 
        discount = 0.0;
}
productType::productType(string s, int x, double y, double z){
    productName = "";
    id = s;
    manufacturer = "";
    
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;
    
    if(y >= 0.0)
        price = y;
    else 
        price = 0.0;
    
    if(z >= 0.0)
        discount = z;
    else 
        discount = 0.0; 
}
productType::productType(string n, string pID, string m, int x, double y, double z){
    productName = n;
    id = pID;
    manufacturer = m;
    
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;
    
    if(y >= 0.0)
        price = y;
    else 
        price = 0.0;
    
    if(z >= 0.0)
        discount = z;
    else 
        discount = 0.0;
}
void productType::set(string n, string pID, string m, int x, double y, double z){
    productName = n;
    id = pID;
    manufacturer = m;
    
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;
    
    if(y >= 0.0)
        price = y;
    else 
        price = 0.0;
    
    if(z >= 0.0)
        discount = z;
    else 
        discount = 0.0;
}
void productType::print()const{
    cout << "Product Name: " << productName << endl;
    cout << "Product ID: " << id << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Quantities In Stock: " << quantitiesInStock << endl;
    cout << "Price: " << price << endl;
    cout << "Discount: " << discount << endl;
}
void productType::setQuantitiesInStock(int x){
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;
}
void productType::updateQuantitiesInStock(int x){
    quantitiesInStock = quantitiesInStock + x;
    
    if(quantitiesInStock < 0)
        quantitiesInStock = 0;
}
int productType::getQuantitiesInStock()const{
    return quantitiesInStock;
}
void productType::setPrice(double x){
    if(x >= 0.0)
        price = x;
    else 
        price = 0.0;
}
double productType::getPrice()const{
    return price;
}
void productType::setDiscount(double d){
    if(d >= 0.0)
        discount = d;
    else 
        discount = 0.0;
}
double productType::getDiscount()const{
    return discount;
}












