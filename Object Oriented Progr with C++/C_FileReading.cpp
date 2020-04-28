// Header files
#include <iostream>
#include <iomanip>
#include <fstream>
// Namespaces
using namespace std;
// Function Prototypes
void readData(ifstream &inputFile, int list[], int size);
void print(int list[], int size);

int main() {
    // Declare variables
    int scores[8] = {0};
    ifstream infile;
    infile.open("Ch8_Ex4Data.txt");
    
    // Error handling
    if (!infile){
        cout << "Cannot open the input file. Program terminates!"
             << endl;
        return 1;
    }
    
    // Calls functions and closes file
    readData(infile, scores, 8);
    print(scores, 8);
    cout << endl;
    infile.close();
    
    return 0;
}


void readData (ifstream &inputFile, int list[], int size){
    // Declare variables
    int score;
    int index;

    // Gets first score
    inputFile >> score;

    // Runs until EOF
    while (inputFile){
        // Gets index
        index = score / 25;

        // Handles the score 200 exception
        if (index == size)
            index--;
        
        // Increments element counter
        list[index]++;

        // Gets next score
        inputFile >> score;
   }
}


// Prints # of students in age range
void print(int list[], int size){
    // Declare variables
    int range;
    int lowRange = 0;
    int upperRange = 24;
    
    // Tell user the ranges
    cout << "    Range        # of Students" << endl;
    
    // For loop to go through array and select ranges
    for (range = 0; range < size; range++){
        cout << setw(3) << lowRange << " - " << setw(3)
             << upperRange << setw(15)
             << list[range] << endl;
        lowRange = upperRange + 1;
        upperRange = upperRange + 25;
        if (range == size -2)
            upperRange++;
    }
    cout << endl;
}

