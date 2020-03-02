// Header files
#include <stdio.h> 
#include <iostream>
#include <cmath>
// Function Prototypes
void fillArray(double arr[], int size);
void printArray(double arr[], int size);
// Namespaces
using namespace std;
  
int main(void) 
{ 
    // Declare variables
    int size = 50;
    double alpha[size];
    
    // Call functions
    fillArray(alpha, size);
    printArray(alpha, size);
    
    return 0; 
} 

// Creates array of random numbers
void fillArray(double arr[], int size){
    for(int i=0; i<25; i++){
        arr[i] = i * i;
    }
    for(int i=25; i<size; i++){
        arr[i] = 3 * i;
    }
}

// Prints array
void printArray(double arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
}

