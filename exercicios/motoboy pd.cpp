#include <iostream>
#include <cstring>

using namespace std;

int n; // quantidade de pedidos
int tempo[2000], pizzas[2000]; //variaveis de valor e peso para cada item
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


	if(cap >= pizzas[i]) //se for possivel pegar o item
	{
		pega = solve(i + 1, cap - pizzas[i]) + tempo[i]; //valor apos pegar o item

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

	int maxpizzas; // maximo de pizzas que pode entregar
	cin >> maxpizzas;
	cin >> n; // quantidade de pedidos


	for(int i = 0; i < n; i++)
	{
		cin >> tempo[i] >> pizzas[i]; // tempo de entrega e numero de pizzas do pedido
	}

	for(int i = 0; i < 2000; i++)
		for(int j = 0; j < 2000; j++)
			pd[i][j] = -1;


	cout << "Tempo: ";
	cout << solve(0, maxpizzas) << " min" << endl;

	return 0;
}
