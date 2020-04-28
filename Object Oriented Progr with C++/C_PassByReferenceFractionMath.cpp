#include <iostream>
void menu(int &menuSel);
void getData(int &a1, int &a2, int &b1, int &b2);
void addFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2);
void subtractFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2);
void multiplyFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2);
void divideFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2);
using namespace std;

int main() {
    int a1, a2, b1, b2, c1, c2, menuSel = 0;
    
    while (menuSel != 9){
    menu(menuSel);
    if (menuSel == 9)
        break;
    getData(a1, a2, b1, b2);
    switch (menuSel){
        case 1:
            addFractions(a1, a2, b1, b2, c1, c2);
            break;
        case 2:
            subtractFractions(a1, a2, b1, b2, c1, c2);
            break;
        case 3:
            multiplyFractions(a1, a2, b1, b2, c1, c2);
            break;
        case 4:
            divideFractions(a1, a2, b1, b2, c1, c2);
            break;
        default:
            break;
    }
    
    cout<<a1<<'/'<<a2<<menuSel<<b1<<'/'<<b2<<'='<<c1<<'/'<<c2;
    }
    return 0;
}


void menu(int &menuSel){
    cout<<"Enter 1 to add."<<endl;
    cout<<"Enter 2 to subtract."<<endl;
    cout<<"Enter 3 to multipy."<<endl;
    cout<<"Enter 4 to divide."<<endl;
    cout<<"Enter 9 to exit."<<endl;
    cin>>menuSel;
    cout<<endl;
}

void getData(int &a1, int &a2, int &b1, int &b2){
    cout<<"Enter numerator of first fraction: ";
    cin>>a1;
    cout<<endl;
    cout<<"Enter demoninator of first fraction: ";
    cin>>a2;
    cout<<endl;
    cout<<"Enter numerator of second fraction: ";
    cin>>b1;
    cout<<endl;
    cout<<"Enter demoninator of second fraction: ";
    cin>>b2;
    cout<<endl;
}


void addFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2){
    c1 = (a1*b2)+(b1*a2);
    c2 = a2 * b2;
}


void subtractFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2){
    c1 = (a1*b2)-(b1*a2);
    c2 = a2 * b2;
}


void multiplyFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2){
    c1 = a1*b1;
    c2 = a2*b2;
}


void divideFractions(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2){
    c1 = a1*b2;
    c2 = a2*b1;
}

