#include <string>

using namespace std;

class productType //Line 1
{ //Line 2
public: //Line 3
productType(); //Line 4
productType(int, double, double); //Line 5
productType(string, int, double, double); //Line 6
productType(string, string, string,
int, double, double); //Line 7
void set(string, string, string, int,
double, double); //Line 8
void print() const; //Line 9
void setQuantitiesInStock(int x); //Line 10
void updateQuantitiesInStock(int x); //Line 11
int getQuantitiesInStock() const; //Line 12
void setPrice(double x); //Line 13
double getPrice() const; //Line 14
void setDiscount(double d); //Line 15
double getDiscount() const; //Line 16
private: //Line 17
string productName; //Line 18
string id; //Line 19
string manufacturer; //Line 20
int quantitiesInStock; //Line 21
double price; //Line 22
double discount; //Line 23
};

