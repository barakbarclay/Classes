#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    string str2;
    int i, j;
    int length;
    string str1[6] = {"Madam", "22", "abBa", "67876", "444244", "trYmeuemyRT"}; 

    for (j = 0; j < 6; j++){
    str2 = str1[j];
    length = str2.length();
    
    for (i = 0; i < length; i++){
        if (str2[i] >= 65 && str2[i] <= 90)
            str2[i] += 32;
    }
    
    if (isPalindrome(str2))
        cout << str1[j] << " is a palindrome";
    if (j <= 2)
        cout << ".";
    else 
        cout << str1[j] << " is not a palindrome";
    cout << endl;
    }
    return 0;
}//main

bool isPalindrome(string str2) 
{
int length = str2.length(); 
for (int i = 0; i < length / 2; i++) {
    if (str2[i] != str2[length - 1 - i]) {
         return false;
    } // if    
  } // for loop
 return true;
}// isPalindrome 

