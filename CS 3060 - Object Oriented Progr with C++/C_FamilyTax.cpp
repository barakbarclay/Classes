#include <iostream>
#include <iomanip> 
void getData(char &mStatus, int &nOfChildren, double &salary, double &pContribPension);
double taxAmount(char mStatus,int nOfChildren, double salary, double pContribPension);
using namespace std;

int main() {
    char mStatus = ' ';
    int nOfChildren = 0; 
    double salary = 0.0, pContribPension = 0.0;
    
    cout<<fixed<<showpoint<<setprecision(2); 
    
    getData(mStatus, nOfChildren, salary, pContribPension);
    
    cout<<endl<<taxAmount(mStatus, nOfChildren, salary, pContribPension);
        
    return 0;
}


void getData(char &mStatus, int &nOfChildren, double &salary, double &pContribPension){
    cout<<"Enter marital status: m or M (married), s or S (single): ";
    cin>>mStatus;
    cout<<endl;
    
    if (mStatus == 'm' || mStatus == 'M'){
        cout<<"Enter number of childern under the age of 14: ";
        cin>>nOfChildren;
        cout<<endl;
    }
    
    cout<<"Enter gross salary for the year: ";
    cin>>salary;
    cout<<endl;
    
    cout<<"Enter percentage of salary conributed to pension (0-6):";
    cin>>pContribPension;
    cout<<endl;
}


double taxAmount(char mStatus,  int nOfChildren, double salary, double pContribPension){
    double taxableAmount = 0.0, tax = 0.0;
    int numberOfDeduction, numberOfPeople = 0;
    
    if(mStatus == 'm' || mStatus == 'M'){
        numberOfDeduction = 7000;
        numberOfPeople = 2 + nOfChildren;
    }
    else{
        numberOfDeduction = 4000;
        numberOfPeople = 1;
    }
    
    pContribPension = pContribPension / 100 * salary;
    
    taxableAmount = salary - ((1500.00 * numberOfPeople) + numberOfDeduction + pContribPension);
    
    if (taxableAmount < 0)
        taxableAmount = 0;
    
    if (0 <= taxableAmount && taxableAmount <= 15000)
        tax = taxableAmount * 0.15;
    else if (15001 <= taxableAmount && taxableAmount <= 40000)
        tax = 2250.00 + .25 * (taxableAmount - 15000);
    else 
        tax = 8460.00 + .35 * (taxableAmount - 40000);
    
    return tax;
}

