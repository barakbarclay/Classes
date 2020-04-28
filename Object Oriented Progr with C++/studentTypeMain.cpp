#include <iostream>
#include <string>
#include "studentType.h"

using namespace std;

int main() {
  studentType student;
  studentType newStudent("Brain", "Johnson", '*', 85, 95, 3.89);

  student.print();
  cout << "***************" << endl << endl;

  newStudent.print();
  cout << "***************" << endl << endl;
}
