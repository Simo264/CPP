#include <iostream>
#include <string>
using namespace std;

int division(int num, int den) 
{ 
	if(den == 0)	
		throw runtime_error("Error::Zero division [line " + to_string(__LINE__) + "]");
	return num/den;	
}

void foo(int v[], int index)
{
	if(index < 0 || index >= 3)
		throw out_of_range("Function foo(int[], int) -> Error::Out of range [line " + to_string(__LINE__) + "]");
}

int main()
{   
	try{
		auto n = division(10,0);
		cout << n << endl;
	}
	catch(runtime_error e){
		cerr << e.what() << endl;
	}
	

	try{
		int v[3]{1,2,3};
		foo(v,4);
	}
	catch(const out_of_range& e){
		cerr << e.what() << endl;
 	}

	return 0;
}
