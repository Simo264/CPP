#include <iostream>
#include <fstream>
using namespace std;

#define deb(x) cout << #x << " " << x << endl;

template<typename... T>
void read(T&... args)
{
    ( (cin >> args), ...);
}

template<typename... T>
void write(const T... args)
{
    ( (cout << args << " "), ...);
}

int main()
{
    /*
    int x(100), y(200);
    deb(x);
    deb(y);
    */

    /*
    int a, b, c, d;
    read(a, b, c, d);
    write(a, b, c, d, "hello world");
    */


    cin.get();
}