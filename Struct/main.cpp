#include <iostream>

struct Vector
{
    int sz = 0;
    double* elem = nullptr;
};

void vector_init(Vector& v, int s)
{
    v.elem = new double[s]; //allocate an array of s doubles
    v.sz = s;

    for(int i = 0; i < s; i++)
        v.elem[i] = i;
}

void read_vector(Vector&v)
{
    if(v.elem != nullptr)
    {
        std::cout << "Size = " << v.sz << std::endl; 
        std::cout << "Elements: " << std::endl;

        for(int i = 0; i < v.sz; i++)
            std::cout << v.elem[i] << std::endl;
        
    }
    else
        std::cout << "You must initialize the vector!\n";
} 

void f(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz; //Access throught name
    int i2 = rv.sz; //Access throught reference
    int i3 = pv->sz; //Access throught pointer
}

int main()
{
    int size = 6;
    Vector v;

    vector_init(v,size);
    read_vector(v);

    getchar();
}