#include <iostream>
#include <functional>
using namespace std;

// Method 1
// using std::function library: void -> return type;  int -> function argument 
void print_modulo(function<void (int)> fun ) 
{
    cout << "- function<void (int)> fun\n\t";
	fun(10);
}

// Method 1.1
// using a pointer to a function
void print_modulo(void (*fun)(int) ) 
{
    cout << "- void (*fun)(int)\n\t";
	fun(10);
}


void foo(int x)
{
    cout << "Foo(int x) function! x=" << x << endl << endl;
}


int main()
{    
    int temp = 8;
    auto lambda = [&temp](int x) { 
        cout << "This is lambda function!" 
            << "temp=" << temp << " " <<  "x=" << x << endl << endl;
    };
    print_modulo(lambda);
    print_modulo(&foo);


	return 0;
}