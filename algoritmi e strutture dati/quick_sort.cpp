#include <iostream>
#include <algorithm>
using namespace std;

int Partition(int a[], int low, int high)
{
	int pivot = a[high];
	int i = low;
	for(int j = low; j < high; j++)
	{
		if(a[j] <= pivot)
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[high]);
	return i;
}
void Quicksort(int a[], int low, int high)
{
	if(low < high)
	{
		int p = Partition(a, low, high);
		Quicksort(a, low, p-1);
		Quicksort(a, p+1, high);
	}
}

int main()
{ 	
	int a[] ={ 1, 5, 76, 3, 44, 31 };  
	int size = sizeof(a) / sizeof(int);
	
	for (size_t i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
	
	Quicksort(a, 0, size - 1);

	for (size_t i = 0; i < size; i++)
		cout << a[i] << " ";
	
	return 0;
}