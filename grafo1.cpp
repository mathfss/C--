#include <iostream>
#include <list>
using namespace std;

struct no
{
	int v; // destino
	int p; // peso
};

int main ()
{
	list<no> adj[10]; // lista de adjacencias
	int u, v; // origem e destino de uma aresta
	int p; // peso da aresta
	no aux; // struct aux p/ inserir as arestas
	list <no>::iterator q; // iterador p/ mostrar a lista de adjacencias
	int i; // contador
	int nVertices = 4; // # vertices do grafo
	int orientado = 0; // 1: orientado, o: nao orientado
	
	// Criando uma aresta
	u = 0;
	v = 1;
	p = 4;

	aux.v = v;
	aux.p = p;

	adj[u].push_back(aux);

	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	// Criando uma aresta
	u = 1;
	v = 2;
	p = 2;

	aux.v = v;
	aux.p = p;

	adj[u].push_back(aux);

	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	// Criando uma aresta
	u = 2;
	v = 3;
	p = 5;

	aux.v = v;
	aux.p = p;

	adj[u].push_back(aux);

	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	// Criando uma aresta
	u = 3;
	v = 0;
	p = 7;

	aux.v = v;
	aux.p = p;

	adj[u].push_back(aux);

	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}

	// Criando uma aresta
	u = 0;
	v = 2;
	p = 3;

	aux.v = v;
	aux.p = p;

	adj[u].push_back(aux);

	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
	
	// Criando uma aresta
	u = 1;
	v = 3;
	p = 1;

	aux.v = v;
	aux.p = p;
	
	adj[u].push_back(aux);

	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;
		adj[v].push_back(aux);
	}
	
	// Mostrando a lista de adjacencias
	for (i = 0; i < nVertices; i++)
		for (q = adj[i].begin(); q != adj[i].end(); q++)
			cout << i << " " << q -> v << " " << q -> p << endl;
		



	return 0;
}
