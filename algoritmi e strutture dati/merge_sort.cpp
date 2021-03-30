#include <iostream>
using std::cout;
using std::endl;


void Merge(int A[],int left, int center, int right)     
{
	int i(0), j(0), k(0); 
	const int sizeLeft = center - left + 1;
    const int sizeRight = right - center; 
    int* L = new int[sizeLeft]();
	int* R = new int[sizeRight]();

	//initializing the value of Left part to L[]
    for(i = 0; i < sizeLeft; i++)
        L[i] = A[left + i];
    
    //initializing the value of Right Part to R[]
    for(i = 0; i < sizeRight; i++)
        R[i] = A[center + i + 1];
    
    i = j = 0;
    //Comparing and merging them
    //into new array in sorted order 
    for(k = left; i < sizeLeft && j < sizeRight; k++)
    {
        if(L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
    //If Left Array L[] has more elements than Right Array R[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while(i < sizeLeft)             
        A[k++] = L[i++];
    
    //If Right Array R[] has more elements than Left Array L[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while(j < sizeRight)
        A[k++] = R[j++];
    
	delete[] L;
	delete[] R;
}

void MergeSort(int A[],int left, int right)    
{                            
    if(left < right)
    {
		int center = (left + right) / 2;
		MergeSort(A, left, center);			// sort the left  run
		MergeSort(A, center + 1, right);	// sort the right run
		Merge(A, left, center, right);		// merge the resulting runs from array B[] into A[]
    }
}

int main()
{ 
	
	int vect[] = { 38, 27, 43, 3, 9, 82, 10 };
	int size = sizeof(vect) / sizeof(int);
	int left = 0;
	int right = size-1;

	/************************/
	cout << "Before:\n";
	for(int i = 0; i < size; i++)
		cout << vect[i] << " ";
	cout << endl;
	/************************/

	MergeSort(vect, left, right);

	/************************/
	cout << "After:\n";
	for(int i = 0; i < size; i++)
		cout << vect[i] << " ";
	/************************/
	return 0;
}
