#include <iostream>
#include "Vector.cpp"
using namespace std;

void vector_init(Vector&v, int sz)
{
    for(int i = 0; i < sz; i++)
        v[i] = i;
}

void read_vector(Vector& v)
{
    cout << "Size = " << v.size() << endl;
    cout << "Elements:\n"; 

    if(v.size() != 0)
    {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
}

int main()
{
    int size = 6;

    Vector v(size);
    vector_init(v,size);
    read_vector(v);
}