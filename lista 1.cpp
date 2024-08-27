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
	list <int> fila; // ponteiro para a fila
	list <int>:: iterator p; // ponteiro para andar na lista
	int x = 1; // var aux para leitura e escrita

	// Lendo elementos e inserindo na fila
	cin >> x;
	do
	{
		fila.push_back(x);
		cin >> x;
	}
	while (x != 0);

	// Lendo elemento para buscá-lo
	cin >> x;

	// Chamando a função
	if (encontrar(fila, x) == true)
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;

	// Removendo elementos
	while (!fila.empty())
		fila.pop_front();

	return 0;
}
