#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v; // destino
	int peso; // peso
};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;

	aux.v = v;
	aux.peso = p;

	adj[u].push_back(aux);

	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
}


int main ()
{
	list<no> adj[10]; // lista de adjacencias
	int u, v; // origem e destino de uma aresta
	int p; // peso da aresta
	list <no>::iterator q; // iterador p/ mostrar a lista de adjacencias
	int i; // contador
	int nVertices; // # vertices do grafo
	int orientado; // 1: orientado, o: nao orientado

	cin >> nVertices >> orientado;

	u = 0;
	v = 0;
	p = 0;

	while (u != -1 && v != -1 && p != -1)
	{
		cin >> u >> v >> p;
		cria_aresta(adj, u, v, p, orientado);
	}

	for (i = 0; i < nVertices; i++)
		for (q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q -> v << " " << q -> peso << endl;

	return 0;
}
