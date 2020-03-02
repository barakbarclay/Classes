#include <iostream>

#include "boxType.h" 
 
using namespace std;

int main()
{
    boxType box1(10, 5, 3);                
    boxType box2(8, 7, 5);               
    boxType box3;                       
    boxType box4;                       

    cout << "box1: " << box1 << endl;                                   

    cout << "box2: " << box2  << endl;                                    

    box3 = box1 + box2;            
    
    cout << "box3: " << box3 << endl;                                   

    box4 = box1 * box2;           
    
    cout << "box4: " << box4 << endl;          

    if (box1 > box2)                   
        cout << "Volume of box1 is greater than the volume "
             << "of box2 ." << endl;                
    else                                             
        cout << "Volume of box1 is less than or equal to the volume "
             << "of box2 ." << endl;     

	box1++;

	cout << "After increment the length, width, and height of "
		 << "box1 by one unit, \nbox1: " 
         << box1 << endl;

	box4 = ++box3;

	cout << "New dimension of box3: " << box3 << endl;
	cout << "New dimension of box4: " << box4 << endl;

    return 0;
}