#include <iostream>
#include <list>

using namespace std;

int soma (list <int> lista)
{
	list <int>:: iterator p; // ponteiro para andar na lista
	int soma = 0; // variavel para armazenar a soma

	// somando os "nós" da lista
	for (p = lista.begin(); p != lista.end(); p++)
		soma += *p;

	return soma;
}

int main ()
{
	list <int> fila; // ponteiro para a fila
	list <int>:: iterator p; // ponteiro para andar na lista
	int x; // var aux para leitura e escrita

	// Lendo elementos e inserindo na fila
	cin >> x;
	do
	{
		fila.push_back(x);
		cin >> x;
	}
	while (x != 0);

	// Saida de dados
	cout << soma(fila) << endl;

	// Removendo elementos
	while (!fila.empty())
		fila.pop_front();

	return 0;
}
