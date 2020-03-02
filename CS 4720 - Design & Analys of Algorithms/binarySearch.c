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
    for (int size = 5000; size <= 100000; size += 5000){
        // Declare variables
        int arr[size]; 
        srand(time(0));
        int searchNum = rand()%size;
    
        // Fills array
        fillArray(arr, size);
    
        // Sorts array
        sort(arr, arr+size);
    
        // Calls Binary Search Function and prints results
        std::clock_t    start;
        start = std::clock();
        int result = binarySearch(arr, 0, size-1, searchNum); 
        std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
        (result == -1)? printf("Element is not present in array\n") 
                      : printf("Element is present at index %d\n", result); 
    }
    return 0; 
} 

//Creates array of random numbers
void fillArray(int arr[], int size){
    srand(time(0));
    for(int i=0; i<size; i++){
        arr[i] = rand()%size;
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

