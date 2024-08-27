#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int, int> ii;

vector<ii> adj[300];
int vis[300], dist[300];

int dijkstra(int origem, int destino)
{
	priority_queue<pair<int, int> > pq;

	for (int i = 0; i < 300; i++)
	{
		dist[i] = INF;
		vis[i] = false;
	}
	dist[origem] = 0;

	pq.push(ii(0, origem));

	while(!pq.empty())
	{
		int u = pq.top().second;

		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;

		for(int i = 0; i < (int)adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			int duv = adj[u][i].second;

			if(dist[v] > dist[u] + duv)
			{
				dist[v] = dist[u] + duv;
				pq.push(ii(-dist[v].v));
			}
		}
	}
	return dist[destino];
}

int main()
{
	int n, m;
	int u, v, c;
	cin >> n >> m;

	while (m--)
	{
		cin >> u >> v >> c;

		ajd[u].push_back(ii(v, c));
		adj[v].push_back(ii(u, c));
	}
	cout << dijkstra(1, 3) << endl;
}
