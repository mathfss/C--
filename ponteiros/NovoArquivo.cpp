#include <iostream>
using namespace std;

int main ()
{
	int a; // uma variavel int
	int *b = NULL; // um ponteiro
	
	a = 2;
	b = &a; // &: operador de referencia, retorna o endereço de a
	
	cout << "a = " << a << endl;
	cout << "b = " << (int)b << endl;
	
	*b = 3; // operador de referencia
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
	return 0;
}