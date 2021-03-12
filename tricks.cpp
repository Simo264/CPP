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


void cpy(char* p, const char* q) // copy 2 strings
{
	while(*p++ = *q++);
}

void print(const char* p) // print a string of chars
{
	while(*p) 
		std::cout << *p++;
}

void print(const int* p) // print an int vector
{
	for(; *p != -1; p++)
		std::cout << *p << " ";
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
