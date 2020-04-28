// Header files
#include <iostream>
// Namespaces
using namespace std;
// Function prorotypes
void getData(int twoDim[][2], int rows);
int averageHigh(int twoDim[][2], int rows);
int averageLow(int twoDim[][2], int rows);
int indexHighTemp(int twoDim[][2], int rows);
int indexLowTemp(int twoDim[][2], int rows);

int main() {
    // Declare variabes
    const int NO_OF_MONTHS = 12;
    int hiLowArray[NO_OF_MONTHS][2];
    int indexHigh;
    int indexLow;
    
    // Gets data from user
    getData(hiLowArray, NO_OF_MONTHS);
    
    // Prints average high and low temperatures
    cout << "Average high temperature: "
         << averageHigh(hiLowArray, NO_OF_MONTHS) << endl;
    cout << "Average low temperature: "
         << averageLow(hiLowArray, NO_OF_MONTHS) << endl;
    
    // Gets and prints highest and lowest temperatures
    indexHigh = indexHighTemp(hiLowArray, NO_OF_MONTHS);
    cout << "Highest temperature: " << hiLowArray[indexHigh][0] << endl;
    indexLow = indexLowTemp(hiLowArray, NO_OF_MONTHS);
    cout << "Lowest temperature: " << hiLowArray[indexLow][1] << endl;
    
    return 0;
}


void getData(int twoDim[][2], int rows){
    // Declare varables
    int i;
    
    // Gets high temperatures from user
    cout << "Enter high temperature for each month" << endl;
    for (i = 0; i < rows; i++)
        cin >> twoDim[i][0];
    
    // Gets low temperatures from user
    cout << "Enter low temperature for each month" << endl;
    for (i = 0; i < rows; i++)
        cin >> twoDim[i][1];
}


int averageHigh(int twoDim[][2], int rows){
    // Declares variables
    int i;
    int sum = 0;
    
    // Gets & returns average high temp
    for (i = 0; i < rows; i++)
        sum = sum + twoDim[i][0];
    if (rows > 0)
        return sum / rows;
    else
        return 0;
}


int averageLow(int twoDim[][2], int rows){
    // Declares variables
    int i;
    int sum = 0;
    
    // Gets & returns average high temp
    for (i = 0; i < rows; i++)
        sum = sum + twoDim[i][1];
    if (rows > 0)
        return sum / rows;
    else
        return 0;
}


int indexHighTemp(int twoDim[][2], int rows){
    // Declares variables
    int i;
    int highIndex = 0;
    
    // Gets and returns highest temp
    for (i = 1; i < rows; i++){
        if (twoDim[highIndex][0] < twoDim[i][0])
            highIndex = i;
    }
    return highIndex;
}
          

int indexLowTemp(int twoDim[][2], int rows){
    // Declares variables
    int i;
    int lowIndex = 0;
    
    // Gets and returns highest temp
    for (i = 1; i < rows; i++){
        if (twoDim[lowIndex][1] > twoDim[i][1])
            lowIndex = i;
    }
    return lowIndex;
}

