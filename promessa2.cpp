#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> >& grafo,int node,vector<bool>& visitados)
{
	visitados[node] = true;
	
	for (int i = 0; i < grafo[node].size(); i++)
	{
		int vizinho = grafo[node][i];
		
		if (visitados[vizinho] == false)
		{
			dfs(grafo, vizinho, visitados);
		}
	}
}

int main(){
	
	int v, a;
	
	cin >> v >> a;
	
	vector<vector<int> > grafo(v+1);
	vector<bool> visitados(v+1, false);
	
	int x, y;
	
	for (int i = 0; i < a; i++)
	{
		cin >> x >> y;
		grafo[x].push_back(y);
	}
	
	int comp = 0;
	
	for(int i = 1; i <= v; i++){
		
		if(!visitados[i]){
			comp++;
			dfs(grafo, i, visitados);
		}
	}
	
	cout << comp << endl;
	
	return 0;
}