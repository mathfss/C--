#include <iostream>
#include <list>

using namespace std;

struct no
{
	int v; // destino
	int peso; // peso
};

void bfs(list<no>adj[], int nVertices, int s)
{
	list<int> Q;
	list<no>::iterator q;
	int p[nVertices];
	int state[nVertices];
	int u, v;
	int L[nVertices];
	
	 for (int i = 0; i < nVertices; i++) 
    {
        state[i] = 0;
        p[i] = -1;
    }
    for (int i = 0; i < nVertices; i++) 
    {
        L[i] = 0;
    }
    
    state[s] = 1;
    Q.push_back(s);
    
    while(!Q.empty()) 
    {
        u = Q.front();
        Q.pop_front(); 

        cout << u << endl; 

        for (q = adj[u].begin(); q != adj[u].end(); q++)
        {
            v = q->v;

            cout << u << " " << v << endl;
			L[v] = 1;

            if(state[v] == 0)
            {
                state[v] = 1;
                p[v] = u; 
                Q.push_back(v);
            }
        }

        state[u] = 2; 
    }
	
	int z;
	for (int i=0; i < nVertices; i++)
	{
		if (L[i] != 0)
			z = nVertices;
		else
		{
			z = -1;
			i = nVertices;
		}
	}
	
	if (z = nVertices)
		cout << "Conexo" << endl;
	else
	{
		cout << "Nao conexo" << endl;
	} 
}

void cria_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
	no aux;

	aux.v = v;
	aux.peso = p;

	adj[u].push_back(aux);
	
	if(orientado == 0)
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}

int main ()
{
	list<no> adj[100000]; // lista de adjacencias
	int u, v; // origem e destino de uma aresta
	int vo; // vertice inicial
	int p; // peso da aresta
	int nVertices; // numero de vertices do grafo
	int orientado = 0;

	cin >> nVertices >> vo;
	cin >> u >> v >> p;

	while (u != -1 && v != -1 && p != -1)
	{
		cria_aresta(adj, u, v, p, orientado);
		p=1;
		cin >> u >> v;
	}
	
	bfs(adj, nVertices, vo);

	return 0;
}