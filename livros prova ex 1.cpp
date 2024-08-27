#include <iostream>
#include <cstring>

using namespace std;


int n; // quantidade de elementos
int interesse[2000], peso[2000]; //variaveis de grau de interesse e peso para cada item
int pd[2000][2000];
int itens_pegos[2000][2000];

int solve(int i, int cap)
{
	int pega, npega;

	if(cap < 0) //caso tenha excedido a capacidade
		return 0;

	if(i == n) // se chegou no ultimo item
		return 0;

	npega = solve(i + 1, cap); // valor se nao pegar o item

	pd[i][cap] = npega;


	if(cap >= peso[i]) //se for possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i]) + interesse[i]; //valor apos pegar o item

		if(pega > npega)  //se pegar for melhor
		{
			itens_pegos[i][cap] = 1; // 1 = peguei o item
			pd[i][cap] = pega;
			return pd[i][cap];
		}
		else
		{
			itens_pegos[i][cap] = 0; // 0 = nao peguei o item
			return pd[i][cap];
		}
	}

	else
		return pd[i][cap]; // se nao for possivel pegar o item
}




int main()
{
	for (int j = 1; j > 0; j++)
	{
		int capacidade;
		cin >> n; // numero de livros na estante
		cin >> capacidade; // capacidade da bolsa


		for(int i = 0; i < n; i++)
		{
			cin >> peso[i] >> interesse[i]; // peso e grau de interesse dos livros
		}

		if(solve(0, capacidade) != 0)
		{
			cout << "Caso " << j << ":" << solve(0, capacidade) << endl;
		}
		else
			j = -1;

	}

	return 0;
}


// O método utilizado neste código foi o de força bruta, para que sempre seja obtido o melhor resultado possível
