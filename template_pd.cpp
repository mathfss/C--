#include <iostream>
#include <cstring>

using namespace std;


int n; // quantidade de elementos
int valor[2000], peso[2000]; //variaveis de valor e peso para cada item
int pd[2000][2000];
int itens_pegos[2000][2000];

int solve(int i, int cap)
{
	int pega, npega;

	if(cap < 0) //caso tenha excedido a capacidade
		return 0;

	if(i == n) // se chegou no ultimo item
		return 0;
	if(pd[i][cap] != -1)
		return pd[i][cap];


	npega = solve(i + 1, cap); // valor se nao pegar o item

	pd[i][cap] = npega;


	if(cap >= peso[i]) //se for possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i]) + valor[i]; //valor apos pegar o item

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
	cout << "Insira a capacidade" << endl;
	cin >> capacidade;
	cout << "Insira a quantidade de elementos" << endl;
	cin >> n;


	for(int i = 0; i < n; i++)
	{
		cout << "Insira o peso e o valor do item" << endl;
		cin >> peso[i] >> valor[i];
	}

	for(int i = 0; i < 2000; i++)
		for(int j = 0; j < 2000; j++)
			pd[i][j] = -1;


	cout << "O valor total foi de: ";
	cout << solve(0, capacidade) << endl;
	cout << "---------------------" << endl;

	//recuperacao de caminho
	int i = 0;
	int j = capacidade;


	while(i != n)  // enquanto eu nao chegar no ultimo item
	{
		if(itens_pegos[i][j] == 0) // se nesse momento a melhor opcao foi nao pegar eu nao pego
			i++; // avanço para o proximo i, mantendo a capacidade

		else // if(caminho[i][j] == 1) /// se nesse momento a melhor opcao for pegar, eu pego
		{
			cout << "Peguei o item " << i << endl; // indico que peguei o item
			cout << "Peso:" << peso[i] << endl;
			cout << "Valor:" << valor[i] << endl;
			cout << "---------------------" << endl;
			j -= peso[i]; // diminuo a capacidade disponivel
			i++; // avanco para o proximo i
		}
	}

	
	return 0;
}
