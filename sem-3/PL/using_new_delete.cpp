/**
 * Problem Definition:
 *  Write a C++ program to store the following information of 10 employees using
 *  dynamic memory allocation
 *  1. Employee Name
 *  2. Employee Number
 *  3. Employee Salary
 *  Define a calculateBonus() function which will calculate the bonus as follows
 *  If salary<10000,bonus=salary+2000
 *  If 10000<salary<20000,bonus=salary+4000
 *  If salary>=20000,bonus=salary+7000
 */

#include <iostream.h>
#include <conio.h>

class Employee {
    char name[100];
    int number;
    long int salary;
    public:
        void setData() {
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee number: ";
            cin >> number;
            cout << "Enter employee salary: ";
            cin >> salary;
        }

        void getData() {
            cout << "Employee name: " << name << endl;
            cout << "Employee number: " << number << endl;
            cout << "Employee salary: " << salary << endl;
            cout << "Employee bonus: " << calculateBonus() << endl;
        }
        long int calculateBonus() {
            if (salary < 10000) {
                return (salary + 2000);
            }
            else if (salary < 20000) {
                return (salary + 4000);
            }
            else {
                return (salary + 7000);
            }
        }
};

void main() {
    clrscr();

    Employee* employees = new Employee[5];
    for(int i = 0; i < 5; i++)
    employees[i].setData();
    for(i = 0; i < 5; i++)
    employees[i].getData();
    delete[] employees;

    getch();
}
