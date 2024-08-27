#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//função para calcular fatorial de x
double fator (int x)
{
	double fat;
	int i;
	
	fat=1;
	for (i=2; i<=x; i++)
		fat= fat*i;
	return fat;
}

int main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	int N, P;
	double C;
	
	cin >> N >> P;
	
	C = fator(N) /(fator(P)*fator(N-P));
	
	cout << C;
	
	return 0;	
}