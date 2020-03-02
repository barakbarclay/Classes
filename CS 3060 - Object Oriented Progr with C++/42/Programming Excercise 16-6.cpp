#include <iostream>
using namespace std;

void insertionSort(int list[], int& len);
void remove(int list[], int& len, int removeItem);
void removeAt(int list[], int& len, int index);
void removeAll(int list[], int& len, int removeItem);
void print(const int list[], int len);

int main() {
    int list[10]{};
	int length = 10;
	int item;
	
	cout << "Please enter 10 intergers: " << endl;
	for (int i = 0; i < 10; i++){
		cin >> list[i];
	}
	print(list, length);
	
	cout << "Enter the postion of the item to be removed." << endl;
	cout << "Enter 0 for the first item and so on:";
	cin >> item;
	cout << endl;
	
	removeAt(list, length, item);
	cout << "List after removing " << item << endl;
	print(list,length);
	
	insertionSort(list, length);
	cout << "List after sorting" << endl;
	print(list,length);
	
    return 0;
}

void removeAll(int list[], int& len, int removeItem){
	int i, j;
	bool found = false;
	
	if (len==0)
		cout << "Cannot delete from an empty list." << endl;
	else {
		i = 0;
		while(i < len){
			if(removeItem == list[i]){
				found = true;
				for (j=i; j < len; j++)
					list[j] = list[j + 1];
				len--;
			}
			else 
				i++;
		}
		
		if (!found)
			cout << removeItem << " is not in the list." << endl;
	}
}

void print(const int list[], int len){
	for(int i = 0; i < len; i++)
		cout << list[i] << " ";
	cout << endl;
}

void removeAt(int list[], int& len, int index){
	if (index < 0 || index > len) {
		cout << "Position of the item to be deleted is out of range." << endl;
		
		if (index < 0)
			cout << "Position of item to be deleted must be nonnegative." << endl;
		else 
			cout << "There are only " << len << " items in the list." << endl;
	}
	else{
		for (int i = index; i < len; i++)
			list[i] = list [i + 1];
		len--;
	}
}

void remove(int list[], int& len, int removeItem){
	int i;
	int loc;
	bool found = false;
	
	if (len == 0)
		cout << "Cannot delete from an empty list." << endl;
	else{
		for (i = 0; i < len; i++){
			if (removeItem == list[i]){
				found = true;
				loc = i;
				break;
			}
        }
			if (found){
				for (i = loc; i < len; i++)
					list [i] = list [i + 1];
				len--;	
			}
			else
				cout << removeItem << " is not in the list." << endl;
		}
}

void insertionSort(int list[], int& len){
	for (int i = 0; i < len; i++){
		int j = i;
		while((j > 0) && (list[j] < list [j-1])){
			int temp = list[j];
			list [j] = list [j-1];
			list [j-1] = temp;
			j--;
		}
	}
}

