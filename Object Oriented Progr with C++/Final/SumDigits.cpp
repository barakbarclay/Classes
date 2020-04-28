#include <iostream>
using namespace std;

long long sumDigits(long long& sum,long long num);

int main(){
	long long num;
	long long sum = 0;
	
	cout << "Please enter an integer: ";
	cin >> num;

	sumDigits(sum,num);

	cout << "The sum of the digits of " << num << " is: " << sum << endl;

	return 0;
}

long long sumDigits(long long& sum,long long num) {
	if(num <= 0) {
		return 0;
	} 
	else {
		sum = sum + (num % 10);
		return sumDigits(sum,num/10);
	}
}
