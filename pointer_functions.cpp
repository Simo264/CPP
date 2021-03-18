#include <iostream>
#include <array>
using namespace std;

/******* Parte 1: array di funzioni ********
float somma(int a, int b){return a+b;}
float sottrazione(int a, int b){return a-b;}
float moltiplicazione(int a, int b){return a*b;}
float divisione(int a, int b){return a/b;}
*******************************************/


/******* Parte 2 passaggio di puntatori a funzione ********
float square(int n){ return n*n; }
float cube(int n) {return n*n*n; }
int sum(int n, float(*fun)(int))
{
	int somma = 0;
	for(int i = 0; i < n; i++)
		somma += fun(i);
	return somma;
}
**********************************************************/


int main()
{   
/******* Parte 1: array di funzioni ********
	//	creo un array di 4 elementi di tipo float(*)(int,int)
	//	ovvero 4 puntatori a funzione
	
	int num(10), num2(34);
	array<float(*)(int a, int b), 4> ptr_fun = {somma, sottrazione, moltiplicazione, divisione};	
	cout << "Addizione [" << num << "," << num2 << "] = " << ptr_fun[0](num,num2) << endl;
	cout << "Sottrazione [" << num << "," << num2 << "] = " << ptr_fun[1](num,num2)<< endl;
	cout << "Moltiplicazione [" << num << "," << num2 << "] = " << ptr_fun[2](num,num2)<< endl;
	cout << "Divisione [" << num << "," << num2 << "] = " << ptr_fun[3](num,num2)<< endl;	
*******************************************/



/******* Parte 2 passaggio di puntatori a funzione ********
	int n = 4;
	cout << "Quadrato=" << sum(n, square) << endl;
	cout << "Cubo=" << sum(n, cube) << endl;
**********************************************************/
	return 0;
}
