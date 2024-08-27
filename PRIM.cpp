#include <iostream>
#include <list>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct no
{
	int v; // destino
	int p; //peso

};

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux; //struct aux p/ inserir as arestas
	//list <no>::iterator q; //iterator p/ mostrar a lsita de adjacencias
	
	aux.v = v;
	aux.p = p;
	adj[u].push_back(aux);
	
	//aresta da volta
	if (orientado == 0)
	{
		aux.v = u;

		adj[v].push_back(aux);
	}
}

void prim(list<no>adj[], int nVertices, int start)
{

	int parent[nVertices]; // vertice pai, será atribuido -1 quando não tiver pai
	int v; // vertice de destino
	int i; //contador
	int distance[1000]; // vetor que armazena distancia
	int dist;
	bool intree[nVertices]; //função bool para verificar intree
	int custo = 0;// variavel que armazena a soma dos custos
	int destino, weight; //variaveis auxiliares
	for( i = 0; i < nVertices; i++)
	{
		intree[i] = false; //inicia todos arvore como falsa
		distance[i] = INT_MAX; //
		parent[i] = -1;//inicia todos pais com -1
	}

	distance[start] = 0; //distancia inicial recebe 0
	v = start; //v recebe o inicio

	while(intree[v] == false)
	{
		intree[v] = true;

		for(list<no>::iterator p = adj[v].begin(); p != adj[v].end(); p++)
		{

			destino = p -> v;
			weight = p -> p;

			if(distance[destino] > weight && intree[destino] == false)
			{
				distance[destino] = weight;
				parent[destino] = v;

			}
		}
		
		v = 0;
		dist = INT_MAX;

		for(i = 0; i < nVertices; i++)
		{

			if(intree[i] == false && dist > distance[i])
			{
				dist = distance[i];
				v = i;
			}
		}
	}

	for(i = 0; i < nVertices; i++)
		custo += distance[i];

	//mostra na tela todas as arestas da arvore
	cout << "Arvore Geradora Minima:" << endl;
	for( i  = 1; i < nVertices; i ++)
		cout << parent[i] << " " << i << endl;
	cout << "Custo: " << custo << endl;

}





int main()
{
	list<no>adj[10]; //adj é um vetor de listas ligadas //lista de adjacencias
	int u, v;//origem e destino de uma aresta
	int p;//peso da aresta
	int nVertices; //#vertices do grafo
	int orientado = 0; //1: orientado, 0: nao orientado
	int start; //variavel pra leitura do vertice inicial

	cin >> nVertices; //le o numero de vertices
	cin >> orientado; //le se o grafo é orientado
	cin >> start; //lê o vertice inicial

	do
	{
		cin >> u; //le destino
		cin >> v; //le origem
		cin >> p; //le peso da aresta
		if ( u != -1 && v != -1 && p != -1)
			//chama a função cria_aresta
			cria_aresta(adj, u, v, p, orientado);
	}
	while (u != -1 && v != -1 && p != -1);

	//função para gerar e mostrar a arvore
	prim(adj, nVertices, start);

	//limpa a memoria
	for(int i = 0; i < nVertices; i++)
		while(!adj[i].empty())
			adj[i].pop_back();


	return 0;
}
