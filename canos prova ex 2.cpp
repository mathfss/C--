#include <iostream>
#include <cstring>

using namespace std;


int n; // quantidade de elementos
int canos[2000], peso[2000]; //variaveis de n canos e peso para cada mala
int pd[2000][2000];
int itens_pegos[2000][2000];

int solve(int i, int cap, int qtd)
{
	int pega, npega;
	
	if(qtd <= 0)
		return 0; // caso tenha excedido a quantidade de malas

	if(cap < 0) //caso tenha excedido a capacidade
		return 0;

	if(i == n) // se chegou no ultimo item
		return 0;
	if(pd[i][cap] != -1)
		return pd[i][cap];


	npega = solve(i + 1, cap, qtd); // valor se nao pegar o item

	pd[i][cap] = npega;


	if(cap >= peso[i]) //se for possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i], qtd - 1) + canos[i]; //valor apos pegar o item

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

	int capacidade;
	int quantidade;
	cin >> n;
	cin >> capacidade;
	cin >> quantidade;


	for(int i = 0; i < n; i++)
	{
		cin >> peso[i] >> canos[i];
	}

	for(int i = 0; i < 2000; i++)
		for(int j = 0; j < 2000; j++)
			pd[i][j] = -1;

	cout << solve(0, capacidade, quantidade) << endl;

	return 0;
}
