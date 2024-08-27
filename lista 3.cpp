#include <iostream>
#include <list>

using namespace std;

int main ()
{
	list <int> fila; // ponteiro para a fila
	list <int>:: iterator p; // ponteiro para andar na lista
	int i; // contador
	int x; // var aux para leitura e escrita
	int soma=0;
	
	// Lendo elementos e inserindo na fila
	for (i=0; i<4; i++)
	{
		cin >> x;
		fila.push_back(x);
	}
	
	for (p = fila.begin(); p != fila.end(); p++)
	{
		soma += *p;
	}
	
	cout << "Soma dos elementos: " << soma << endl;
	
	// Liberando memoria alocada pela lista ligada
	while (!fila.empty())
		fila.pop_front();
	
	return 0;
}