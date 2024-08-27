/*
	Exemplo de como resolver o problema da mochila usando as estratégias da força bruta e programação dinâmica.
	A principal diferença está no uso da memória para armazenar soluções pré calculadas.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 110, maxp = 1000, maxv = 1000; // maxp = 1e5+10 --> e = 10 elevado a: // exemplo 1e5 = 1 * 10^5 + 10

int valor[maxn], peso[maxn], volume[maxn], n, C, V;
int dp[maxn][maxp][maxv];
bool vis[maxn][maxp][maxv];

long long programacao_dinamica(int i, int C, int V) {
	// Verifica se é o último item (caso base, não há mais itens para se considerar)
	if(i == n+1) return 0;
	
	// Caso existam itens para considerar, diferente da força bruta, a memória (matriz dp) deve ser verificada para saber se esse cálculo já foi feito antes
	// Para isso, uma matriz de visitação (vis) é utilizado para saber se a posição já foi visitada anteriormente
	if(vis[i][C][V]) return dp[i][C][V];
	
	// Caso não tenha sido visitado ainda,a visita é feita:
	vis[i][C][V] = 1;
	
	// (Primeira possibilidade) Não adicionar o elemento
	dp[i][C][V] = programacao_dinamica(i+1, C);
	
	// (Segunda possibilidade) Adicionar o elemento caso não ultrapasse o limite de capacidade
	// Devemos retirar o peso do item selecionado da capacidade
	if(C >= peso[i] && V >= volume[i])
		dp[i][C][V] = max(
			dp[i][C][V],
			 programacao_dinamica(i+1, C - peso[i], V - volume[i]) + valor[i]
			 );
	
	return dp[i][C][V];
}

int main() {
	int C;
	int V;
	
	// Entrando com o número de itens e a capacidade da mochila
	cin >> n >> C >> V;// scanf("%d %d", &n, &C); // scanf = cin
	
	// Entrando com os pesos e os valores de cada um dos itens
	for(int i = 1; i <= n; i++)
		   cin >> peso[i] >> valor[i] >> volume[i]	//scanf("%d %d", &peso[i], &valor[i], &volume[i]);
	
	// Exibindo a solução por força bruta
	// printf("%lld\n", forca_bruta(1, C)); // printf = cout
	
	// Exibindo a solução por programação dinâmica
	cout << programacao_dinamica(1, C, V)// printf("%lld\n", programacao_dinamica(1, C));
	
}

/*
	Caso de teste:
	input:
	4 10
	7 42
	3 12
	4 40
	5 25
	
	output:
	65
	65

*/