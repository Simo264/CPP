#include <iostream>
using namespace std;

void PrintArray(int* A, int size){
    for(int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}
int GetMax(int* A, int size){
    int max = A[0];
        for(int i = 0; i < size; i++)
            if(A[i] > max)
                max = A[i];
    return max;
}


/* Versione "non stabile"

void CountingSort(int* A, int size){
    int min = A[0];
    int max = A[0];
    for(int i = 0; i < size; i++){
        if(A[i] > max)          max = A[i];
        else if (A[i] < min) min = A[i];
    }
    
    int lenC = (max - min) + 1;
    int* c = new int[lenC]();
    for(int i = 0; i < size; i++){
        c[A[i] - min]++;
    }

    int k = 0;
    for(int i = 0; i < lenC; i++){
        while(c[i] > 0){
            A[k] = i + min;
            k++;
            c[i]--;
        }
    }
    delete[] c;
}


*/


/* Versione "stabile" */
void CountingSort(int* A, int size){
    int k = GetMax(A, size);
    int* output = new int[size]();  // create output array [size] and init to 0
    int* count = new int[k]();      // create count array [max] and init to 0
    
    // increase number count in count array.    
    for (int i = 0; i < size; i++)
        count[A[i]]++;              
    
    //find cumulative frequency
    for (int i = 1; i < size; i++)
        count[i] += count[i - 1];
    
    //decrease count for same numbers
    for (int i = size - 1; i >= 0; i--)
        output[--count[A[i]]] = A[i];

    for (int i = 0; i < size; i++)
        A[i] = output[i];  
    
    delete[] count;
    delete[] output;
}

int main()
{ 	
    int A[] = { 7, 2, 2, 7, 7, 1, 4, 5, 3, 2 };
    int size = sizeof(A) / sizeof(int);
    PrintArray(A, size);
    CountingSort(A, size);
    PrintArray(A, size); 
    
    return 0;
}
