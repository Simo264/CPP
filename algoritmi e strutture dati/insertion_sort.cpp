#include <iostream>
using std::cout;
using std::endl;

void swap(int& x, int& y)
{
	x = (x ^ y); 
	y = (x ^ y); 
	x = (x ^ y);
}

void InsertionSort(int vector[], int N)
{
	for(int i = 1; i < N; i++)
		for(int j = i; j > 0 && vector[j-1] > vector[j]; j--)
			swap(vector[j], vector[j-1]);
}

int main()
{ 
	
	int vect[] = { 38, 27, 43, 3, 9, 82, 10 };
	int size = sizeof(vect) / sizeof(int);
	InsertionSort(vect, size);

	for(int i = 0; i < size; i++)
		cout << vect[i] << " ";
	
	return 0;
}
