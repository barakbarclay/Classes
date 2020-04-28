// Header files
#include <stdio.h> 
#include <time.h>
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
// Function Prototypes
void fillArray(int arr[], int size);
int binarySearch(int arr[], int left, int right, int searchNum);
// Namespaces
using namespace std;
  
int main(void) 
{ 
    // Set up rand function and declare variables
    srand(time(0));
    double searchTime = 0.0;
    
    // Prints welcome
    printf("Binary Search:\n\n");
    
    // Increments array size by 5000 each iteration
    for (int size = 5000; size <= 100000; size += 5000){
        // Runs each size 100 times to get an average
        for (int i= 1; i <= 100; i++){
            // Declare variables
            int arr[size]; 
            int searchNum = rand()%100001;
    
            // Fills array
            fillArray(arr, size);
    
            // Sorts array
            sort(arr, arr+size);
    
            // Calls Binary Search Function and prints results
            std::clock_t    start;
            start = std::clock();
            binarySearch(arr, 0, size-1, searchNum); 
            searchTime += (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000000);
        }
        searchTime /= 100.0;
        printf("Average time taken for array size %d: %.2lf us\n", size, searchTime);
        searchTime = 0.0;
    }
    return 0; 
} 

//Creates array of random numbers
void fillArray(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i] = rand()%100001;
    }
}

// Binary Search Function
int binarySearch(int arr[], int left, int right, int searchNum) { 
    if (right >= left) { 
        int mid = left + (right - left)/2; 
  
        // Returns index if found
        if (arr[mid] == searchNum)
            return mid; 
  
        // Continues search on left side of array
        if (arr[mid] > searchNum)
            return binarySearch(arr, left, mid-1, searchNum); 
  
        // Continues search on right side of array
        return binarySearch(arr, mid+1, right, searchNum); 
    } 
  
    // Returns -1 if not found
    return -1; 
} 

