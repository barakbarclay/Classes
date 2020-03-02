//Header file section
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;
//main function
int main()
{
//variables declartion
ifstream inFile;
char answers[ 20 ];
string id;
char response;
char fileName[ 25 ];
int testScore;
//prompt and read the input file name
cout << "\n\n\tEnter the input file name : ";
cin >> fileName;
// open the input file.
inFile.open( fileName );
// Display error when the file was not opened
if( !inFile.is_open())
{
cout << "Unable to open the input file.";
system( "pause" );
exit(1);
}
// Dispaly a heading
cout << "\n\n ID\t\t\t\t Answers \t\t\t\tSc Gr";

// read the correct answers from the file
for ( int i = 0; i < 20; i++ )
inFile >> answers[ i ];

// read the input from the file
while( ( inFile >> id ) != NULL )
{
// print id
cout << "\n" << id << " ";

// discard the white space between ID & answers
inFile.get( response);

// initialize the score to zero
testScore = 0;

// read student responses from the file
for ( int i = 0; i < 20; i++ )
{
// read an answer character from the file
inFile.get( response);

// print the response on the screen
cout << " " << response;

// compare the responses with answers
if ( response == ' ' )
testScore += 0; // no answer
else
if ( response == answers[ i ] )
testScore += 2;// correct answer
else
testScore += -1;// wrong answer
} // end for

cout << " " << testScore << " ";
double p = testScore * 2.5;
// compute and print the grade
if ( p >= 90 )
cout << 'A';
else
if ( p >= 80 )
cout << 'B';
else
if ( p >= 70 )
cout << 'C';
else
if ( p >= 60 )
cout << 'D';
else
cout << 'F';
}
system("pause");
return 0;
}
