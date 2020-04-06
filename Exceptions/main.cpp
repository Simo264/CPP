#include <iostream>
#include "Vector.cpp"
using namespace std;

void PAUSE()
{
    cout << "Press any key to continue. . . ";
    getchar();
}

void vector_init(Vector& v)
{
    for(int i = 0; i < v.size(); i++)
        v[i] = i;
}

void f(Vector& v)
{
    try
    {
        v[10] = 10;
    }
    catch (const out_of_range& e)
    {
        cerr << e.what() << '\n';
    }
    
}

void test()
{
    try
    {
        Vector v(-10);
    }
    catch(const length_error& le) //handle negative size
    {
        cerr << le.what() << '\n';
    }
    catch(const bad_alloc& be) //handle memory exhausition
    {
        cerr << be.what() << "\n";
    }
    
}

int main()
{
    int size = 5;
    Vector v(size);
    
    f(v);
    test();

    PAUSE();
}