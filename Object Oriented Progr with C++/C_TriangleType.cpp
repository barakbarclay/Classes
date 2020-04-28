#include <iostream>

using namespace std;

enum triangleType{scalene, isosceles, equilateral, noTriangle};

triangleType triangleShape(double side1, double side2, double side3);
void printShape(triangleType triangle);

int main() {
    double lenSide1, lenSide2, lenSide3;
    
    cout<<"Enter the lengths of the three sides of a triangle:"<<endl;
    cin>>lenSide1>>lenSide2>>lenSide3;
    cout<<endl;
    
    cout<<"The shape of the triangle is:";
    printShape(triangleShape(lenSide1, lenSide2, lenSide3));
    cout<<endl;
    
    return 0;
}

triangleType triangleShape(double side1, double side2, double side3){
    if (side1 == side2 && side2 == side3)
        return equilateral;
    else if ((side1 + side2 > side3) &&
            (side1 + side3 > side2) &&
            (side2 + side3 > side1))
        if (side1 == side2 || side2 == side3 || side1 == side3)
            return isosceles;
        else 
            return scalene;
    else
        return noTriangle;
}

void printShape(triangleType triangle){
    switch (triangle){
        case scalene:
            cout<<"scalene"<<endl;
            break;
        case isosceles:
            cout<<"isosceles"<<endl;
            break;
        case equilateral:
            cout<<"equilateral"<<endl;
            break;
        case noTriangle:
            cout<<"noTriangle"<<endl;
    }
}
