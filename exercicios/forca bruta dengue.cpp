#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
	int distancia[100][100]; // para armazenar as distancias
	int n; // numero de focos de dengue
	int casa_joao;

	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			cin >> distancia[i][j];
			distancia[j][i] = distancia[i][j];
		}

	cin >> casa_joao;

	int v[100]; // vetor de permutacao
	int p; // variavel auxiliar
	int menor_distancia; // menor distancia
	int distancia_caminho; // distancia de cada caminho

	p = 0;
	for(int i = 0; i < n; i++)
		if(i != casa_joao)
		{
			v[p] = i;
			p++;
		}


	menor_distancia = INT_MAX;
	do
	{
		distancia_caminho = distancia[casa_joao][v[0]];

		for(int i = 0; i < n - 2; i++)
			distancia_caminho += distancia[v[i]][v[i + 1]];

		distancia_caminho += distancia[v[n - 2]][casa_joao];

		menor_distancia = min(menor_distancia, distancia_caminho);
	}
	while(next_permutation(v, v + (n - 1)));

	cout << menor_distancia << endl;

	return 0;
}


