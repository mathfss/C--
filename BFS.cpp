#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v; // destino
	int peso; // peso
};

void cria_aresta(list<no>adj[], int u, int v, int p)
{
	no aux;

	aux.v = v;
	aux.peso = p;

	adj[u].push_back(aux);
}

void bfs(list<no>adj[], int nVertices, int s)
{
	list<int> lista;
	bool visitados[nVertices]; // vetor de visitados

	for(int i = 0; i < nVertices; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << s << " ...\n";
	visitados[s] = true; // marca como visitado

	while(true)
	{
		list<no>::iterator it;
		for(it = adj[s].begin(); it != adj[s].end(); it++)
		{
			if(!visitados[it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; // marca como visitado
				lista.push_back(*it); // insere na lista
			}
		}

		// verifica se a fila NÃO está vazia
		if(!lista.empty())
		{
			s = lista.front(); // obtém o primeiro elemento
			lista.pop_front(); // remove da fila
		}
		else
			break;
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
		cria_aresta(adj, u, v, p);
	}
	
	grafo.bfs(0)

	//for (i = 0; i < nVertices; i++)
	//	for (q = adj[i].begin(); q != adj[i].end(); q++)
	//		cout << i << " " << q -> v << " " << q -> peso << endl;

	return 0;
}