#include <iostream>
#include "vector.cpp"
using namespace std;

void function(int n)
{
    vector v(n);

    // use vector v...

    {
        vector v2(2*n);

        // use vector v and vector v2...

    } // v2 is destroyed here!

    // use vector v...

} // v is destroyed here!

void print(vector& v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

int main()
{   
    vector v = {1,2,3,4,5,6,7};
}