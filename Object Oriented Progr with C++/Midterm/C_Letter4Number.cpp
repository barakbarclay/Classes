#include <iostream>

using namespace std;

int main() {
    int num = 0;
    
    cout << "Enter an integer between 0 and 35:";
    cin >> num;
    
    if (num <= 9)
        cout << num;
    else
        cout << static_cast<char>(num+55);
    
    return 0;
}
