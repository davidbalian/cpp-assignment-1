#include "Matrix.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix() {
	rowsOne = 0;
	colsOne = 0;
	rowsTwo = 0;
	colsTwo = 0;
}

void Matrix::readMatrix(bool readOne) {
	cout << "MATRIX ONE" << endl;
	cout << "Enter rows: ";
	cin >> rowsOne;
	cout << "Enter columns: ";
	cin >> colsOne;
	
	for (int i = 0; i < rowsOne; i++) {
		for (int j = 0; j < colsOne; j++) {
			cout << "Enter item in row " << i + 1 << " and column " << j + 1 << ": ";
			cin >> matrixOne[i][j];
		}
	}
	
	if (!readOne) {
		cout << "MATRIX TWO" << endl;
		cout << "Enter rows: ";
		cin >> rowsTwo;
		cout << "Enter columns: ";
		cin >> colsTwo;
		
		for (int i = 0; i < rowsTwo; i++) {
			for (int j = 0; j < colsTwo; j++) {
				cout << "Enter item in row " << i + 1 << " and column " << j + 1 << ": ";
				cin >> matrixTwo[i][j];
			}
		}
	}
}

void Matrix::printMatrix() {
	for (int i = 0; i < colsOne; i++) {
		for (int j = 0; j < colsOne; j++) {
			cout << finalMatrix[i][j] << " ";
		}
		
		cout << endl;
	}
}

void Matrix::addSubtract(int sign) {	
	if (rowsOne == rowsTwo && colsOne == colsTwo) {
		if (sign == 1) {
			for (int i = 0; i < rowsOne; i++) {
				for (int j = 0; j < colsOne; j++) {
					finalMatrix[i][j] = matrixOne[i][j] + matrixTwo[i][j];
				}
			}
		} else {
			for (int i = 0; i < rowsOne; i++) {
				for (int j = 0; j < colsOne; j++) {
					finalMatrix[i][j] = matrixOne[i][j] - matrixTwo[i][j];
				}
			}
		}
		
		printMatrix();
	} else {
		cout << "ERROR: MATRICES NOT OF SAME DIMENSIONS" << endl;
	}
}

void Matrix::multiply() {
	if (colsOne == rowsTwo) {
		for (int i = 0; i < colsOne; i++) {
			for (int j = 0; j < colsOne; j++) {
				finalMatrix[i][j] = 0;
				for (int k = 0; k < colsOne; k++)
					finalMatrix[i][j] += matrixOne[i][k] * matrixTwo[k][j];
			}
		}
		
		printMatrix();
	} else {
		cout << "ERROR: COLUMNS OF MATRIX ONE DO NOT EQUAL THE ROWS OF MATRIX TWO" << endl;
	}
}

void Matrix::inverse() {
	float det = 0;
	
	if (rowsOne != colsOne) {
		cout << "ERROR: MATRIX IS NOT SQUARE" << endl;
	} else {
		if (rowsOne == 2) {
			det = matrixOne[0][0] * matrixOne[1][1] - (matrixOne[0][1] * matrixOne[1][0]);
			
			float tempMatrix[2][2] = {0};
			
			tempMatrix[0][0] = matrixOne[1][1];
			tempMatrix[0][1] = -matrixOne[0][1];
			tempMatrix[1][0] = -matrixOne[1][0];
			tempMatrix[1][1] = matrixOne[0][0];
			
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					finalMatrix[i][j] = (1 / det) * tempMatrix[i][j];
				}
			}
			
			printMatrix();
		} else {
			for(int i = 0; i < rowsOne; i++)
				det = det + 
				(matrixOne[0][i]
				* (matrixOne[1][(i + 1) % rowsOne]
				* matrixOne[2][(i + 2) % rowsOne]
				- matrixOne[1][(i + 2) % rowsOne]
				* matrixOne[2][(i + 1) % rowsOne]));

			for(int i = 0; i < rowsOne; i++){
				for(int j = 0; j < rowsOne; j++) {
					cout << fixed << setprecision(2) << 
					((matrixOne[(j + 1) % rowsOne][(i + 1) % rowsOne]
					* matrixOne[(j + 2) % rowsOne][( i+ 2) % rowsOne])
					- (matrixOne[(j + 1) % rowsOne][(i + 2) % rowsOne]
					* matrixOne[(j + 2) % rowsOne][(i + 1) % rowsOne])) / det << " ";
				}
				cout << endl;
			}
		}
	}
}
