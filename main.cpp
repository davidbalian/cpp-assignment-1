#include <iostream>
#include <iomanip>
#include "Matrix.hpp"

using namespace std;

int main() {
	int operation = 0;
	Matrix matrix;
	
	cout << "Press 1 for Addition" << endl;
	cout << setw(23) << "2 for Subtraction" << endl;
	cout << setw(26) << "3 for Multiplication" << endl;
	cout << setw(19) << "4 for Inverse" << endl;
	cout << setw(15) << "5 to EXIT" << endl;
	
	do {
		cout << "\nOperation: ";
		cin >> operation;
		
		switch (operation) {
			case 1:
				matrix.readMatrix(0);
				matrix.addSubtract(1);
				break;
			case 2:
				matrix.readMatrix(0);
				matrix.addSubtract(0);
				break;
			case 3:
				matrix.readMatrix(0);
				matrix.multiply();
				break;
			case 4:
				matrix.readMatrix(1);
				matrix.inverse();
				break;
			default:
				break;
		}
	} while (operation != 5);
	
	cout << "EXITING" << endl;
	
	return 0;
}
