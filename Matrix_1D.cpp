#include <iostream>
using namespace std;

int main()
{   
	const int NUM_ROWS = 3;
	const int NUM_COL = 3;

	int matrix_2D[NUM_ROWS][NUM_COL] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int matrix_1D[NUM_COL*NUM_ROWS]{1,2,3,4,5,6,7,8,9};
	
	cout << "PRINT MATRIX 2D...\n";
	for(int i = 0; i < NUM_ROWS; i++)
	{
		for(int j = 0; j < NUM_COL; j++)
			cout << matrix_2D[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "PRINT MATRIX 1D...\n";
	for(int i = 0; i < NUM_ROWS; i++)
	{
		for(int j = 0; j < NUM_COL; j++)
			cout << matrix_1D[(i*NUM_COL) + j] << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}
