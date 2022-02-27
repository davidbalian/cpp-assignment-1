#include <iostream>

#define MAX_ROW 100
#define MAX_COL 100

class Matrix {
public:
	Matrix();
	void readMatrix(bool);
	void printMatrix();
	void addSubtract(int);
	void multiply();
	void inverse();
private:
	int rowsOne, colsOne, rowsTwo, colsTwo;
	float finalMatrix[MAX_ROW][MAX_COL];
	float matrixOne[MAX_ROW][MAX_COL];
	float matrixTwo[MAX_ROW][MAX_COL];
};
