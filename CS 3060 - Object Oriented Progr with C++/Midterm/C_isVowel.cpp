#include <iostream>

using namespace std;

//define globals
bool isVowel(char ch);

int main() {
    //define vars
    char ch;
        
    cout << "Enter a letter:";
    cin >> ch;
    cout << endl;
    cout << ch << " is a vowel: " << isVowel(ch) << endl;
    
    return 0;
}

bool isVowel(char ch){
    
        switch (ch){
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':                
        case 'o':
        case 'u':                
    return true;
    default:
    return false;
        }
}

