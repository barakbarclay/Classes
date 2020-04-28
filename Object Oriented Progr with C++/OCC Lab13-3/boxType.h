#ifndef boxType_H
#define boxType_H

#include "rectangleType.h"
 
class boxType: public rectangleType
{
        //Overload the stream insertion and extraction operators
    friend ostream& operator<<(ostream&, const boxType &);
    friend istream& operator>>(istream&, boxType &);

public:
    void setDimension(double l, double w, double h);
      //Function to set the length, width, and height 
      //of the box.
      //Postcondition: length = l; width = w; height = h;

    double getHeight() const;
      //Function to return the height of the box.
      //Postcondition: The value of height is returned. 

    double area() const;
      //Function to return the surface area of the box.
      //Postcondition: The surface area of the box is 
      //                calculated and returned.

    double volume() const;
      //Function to return the volume of the box. 
      //Postcondition: The volume of the box is 
      //               calculated and returned.

    boxType();
      //Default constructor
      //Postcondition: length = 0; width = 0; height = 0;

    boxType(double l, double w, double h);
      //Constructor with parameters
      //Postcondition: length = l; width = w; height = h;

    //Overload the arithmetic operators
    boxType operator + (const boxType &) const;
    boxType operator - (const boxType &) const;
    boxType operator * (const boxType&) const;

        //Overload the increment and decrement operators
    boxType operator ++ ();          //pre-increment
    boxType operator ++ (int);       //post-increment
    boxType operator -- ();          //pre-decrement
    boxType operator -- (int);       //post-decrement

      //Overload the relational operators
    bool operator == (const boxType&) const;
    bool operator != (const boxType&) const;
    bool operator <= (const boxType&) const;
    bool operator < (const boxType&) const;
    bool operator >= (const boxType&) const;
    bool operator > (const boxType&) const;

protected:
    double height;
};

#endif