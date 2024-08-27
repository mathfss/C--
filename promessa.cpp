#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main ()
{
	int t;
	cin >> t;
	int n2;
	
	for (int t = 1; t <= t; t++)
	{
		int n, m;
		cin >> n >> m;
		
		vector<vector<int> > grafo(n+1, vector<int>(n+1, 0));
		
		for (int i=0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			grafo[x][y]=1;
			grafo[y][x]=1;
		}
		n2 = n;
	}
	
	bool cumprida = true;
	
	for (int i=1; i <= n2; i++)
	{
		for (int j=1; j <= n2; j++)
		{
			if (grafo[i][j] == 0)
			{
				cumprida =  false;
				break;
			}
		}
	}
	
	if (cumprida)
	{
		cout << "Caso #" << t << ": a promessa foi cumprida" << endl;
	}
	else
	{
		int faltando = 0;
		
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (grafo[i][j] == 0)
				{
					faltando++;
				}
			}
		}
		cout << "Caso #" << t << ": ainda falta(m) " << faltando << " estrada(s)"
	}
	
	return 0;
}