/**
 * Problem definition:
 *  Write a C++ program to store the product name, product code and product
 *  price. Count the number of product objects created by using static member
 *  and static member function.
 */

#include <iostream.h>
#include <conio.h>
#include <stdio.h>

class Product {
	public:
		static int count;
		char name[100];
		int code;
		float price;
	public:
		Product() {
			count++;
		}

		static int getCount() {
			return count;
		}

		void getData(){
			cout << "Product Name: ";
			gets(name);
			cout << "Product code: ";
			cin >> code;
			cout << "Product price: ";
			cin >> price;
		}
};

int Product::count = 0;

void main() {
	clrscr();
	Product products[3];

	for(int i = 0; i < 3; i++) {
		products[i].getData();
	}

	cout << "Total products: " << Product::getCount();
	getch();
}

/**Output
Product Name: a
Product code: 1
Product price: 123
Product Name: b
Product code: 2
Product price: 123
Product Name: c
Product code: 3
Product price: 123
Total products: 3
*/
