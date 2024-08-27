#include <iostream>
#include <list>

using namespace std;

bool encontrar (list <int> lista, int x)
{

	// Declarando ponteiro auxiliar
	list <int> :: iterator p;

	// Buscando o numero na lista
	for (p = lista.begin(); p != lista.end(); p++)
	{
		if (*p == x)
			return true;
	}
	return false;
}

int main ()
{
	list <int> lista1; // ponteiro para a fila
	list <int> lista2;
	list <int> lista3;
	list <int>:: iterator p; // ponteiro para andar na lista
	int x; // var aux para leitura e escrita
	int k =0;
	int j=0;

	// Lendo elementos e inserindo na fila
	cin >> x;
	do
	{
		lista1.push_back(x);
		cin >> x;
	}
	while (x != 0);
	
	cin >> x;
	do
	{
		lista2.push_back(x);
		if (encontrar (lista1, x) == false)
			lista3.push_front(x);
		cin >> x;
	}
	while (x != 0);
	
	
	for (p = lista3.begin(); p != lista3.end(); p++)
	{
		if (*p < *p++)
		{
			k = *p;
			lista3.push_front(k);
			j++;
			*p++;
		}
		
		else
		{
			*p++;
		}
	}
	
	
	while (!lista3.empty())
	{
		x = *lista3.begin();
		cout << x << " ";
		lista3.pop_front();
	}

	return 0;
}
