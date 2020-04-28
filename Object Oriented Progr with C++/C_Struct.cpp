#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct computerType{
    string manufacturer;
    string modelType;
    string processorType;
    int ram;
    int hardDriveSize;
    int yearBuilt;
    double price;
};

int main() {
    computerType computer;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Enter the name of the manufacturer: ";
    getline(cin, computer.manufacturer);
    cout << endl;
    
    cout << "Enter the model of the computer of the computer: ";
    getline(cin, computer.modelType);
    cout << endl;
    
    cout << "Enter processor type: ";
    getline(cin, computer.processorType);
    cout << endl;
    
    cout << "Enter the size of the ram (in GB): ";
    cin >> computer.ram;
    cout << endl;
    
    cout << "Enter the size of hard drive (in GB): ";
    cin >> computer.hardDriveSize;
    cout << endl;
    
    cout << "Enter the year the computer was built: ";
    cin >> computer.yearBuilt;
    cout << endl;
    
    cout << "Enter the price: ";
    cin >> computer.price;
    cout << endl;
    
    cout << "Manufacturer: " << computer.manufacturer << endl;
    cout << "Model: " << computer.modelType << endl;
    cout << "Processor: " << computer.processorType << endl;
    cout << "Ram: " << computer.ram << endl;
    cout << "Hard Drive Size: " << computer.hardDriveSize << endl;
    cout << "Year Built: " << computer.yearBuilt << endl;
    cout << "Price: $" << computer.price << endl;
    
    return 0;
}

