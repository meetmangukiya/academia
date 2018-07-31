/**
 * Problem Definition:
 *  Write a C++ program to accept Roll Number, Marks Obtained and TotalMarks of
 *  a student. Calculate the percentage scored by the student. Display the roll
 *  number, marks obtained, total marks and the percentage scored by the
 *  student. Use getter-setter methods.
 */

#include <iostream>
#include <conio.h>

using namespace std;

class Student {
    int rollNo;
    float marksObtained;
    float totalMarks;

    public:
    void setData() {
        cout << "Enter roll no: ";
        cin >> rollNo;
        cout << "Enter marks obtained: ";
        cin >> marksObtained;
        cout << "Enter total marks: ";
        cin >> totalMarks;
    }

    void getData() {
        cout << "Roll no: " << rollNo;
        cout << "Marks obtained: " << marksObtained;
        cout << "Total marks: " << totalMarks;
        cout << "Percentage: " << marksObtained / totalMarks * 100;
    }

};

int main() {
    clrscr();

    Student st1;
    st1.setData();
    st1.getData();

    getch();
    return 0;
}

/** Output
Enter roll no: 1
Enter marks obtained: 12
Enter total marks: 56
Roll No: 1
Marks Obtained: 12
Total marks: 56
Percentage: 21.428571
*/
