#ifndef H_rectangleType
#define H_rectangleType

#include <iostream>
  
using namespace std;
 
class rectangleType
{
        //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const rectangleType&);
    friend istream& operator>>(istream&, rectangleType&);

        //Overload the arithmetic operators
    friend rectangleType operator+(const rectangleType&, 
                                   const rectangleType&);
    friend rectangleType operator-(const rectangleType&, 
                                   const rectangleType&);
    friend rectangleType operator*(const rectangleType&, 
                                   const rectangleType&);


        //Overload the increment and decrement operators
    friend rectangleType operator++(rectangleType&);      
        //pre-increment
    friend rectangleType operator++(rectangleType&, int);      
       //post-increment
    friend rectangleType operator--(rectangleType&);      
       //pre-decrement
    friend rectangleType operator--(rectangleType&, int);      
       //post-decrement

       //Overload the relational operators
    friend bool operator==(const rectangleType&, 
                           const rectangleType&);
    friend bool operator!=(const rectangleType&, 
                           const rectangleType&);
    friend bool operator<=(const rectangleType&, 
                           const rectangleType&);
    friend bool operator<(const rectangleType&, 
                          const rectangleType&);
    friend bool operator>=(const rectangleType&, 
                           const rectangleType&);
    friend bool operator>(const rectangleType&, 
                          const rectangleType&);

public:
    void setDimension(double l, double w);
    double getLength() const;
    double getWidth() const;
    double area() const;
    double perimeter() const;
 
    rectangleType();
    rectangleType(double l, double w);

protected:
    double length;
    double width;
};

#endif