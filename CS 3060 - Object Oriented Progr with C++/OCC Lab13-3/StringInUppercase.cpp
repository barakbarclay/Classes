#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char *str;
    int strLen;
    int len;
    char ch;
    int i;
    
    cout << "Enter the size of the string:";
    cin >> strLen;
    cout << endl;
    cin.get(ch);
    str = new char[strLen + 1];
    
    cout << "Enter a string of length at most " << strLen << ":";
    cin.get(str, strLen+1);
    cout << endl;
    cout << "String in upper case letters is:" << endl;
    len = strlen(str);
    
    for (i = 0; i < len; i++)
    	cout << static_cast<char>(toupper(str[i]));
    cout << endl;

    return 0;
}
