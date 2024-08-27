#include <iostream>
using namespace std;

int main ()
{
	int *v = NULL; // ponteiro para o vetor
	int N; // tamanho desejado para o vetor
	int i; // contador
	
	// Lendo tamanho desejado para o vetor
	cin >> N;
	
	// Alocando memória para o vetor
	v = new int[N];
	
	// Preenchendo o vetor
	for (i=0; i < N; i++)
		v[i] = i;
	
	// mostrando o vetor
	for (i=0; i < N; i++)
		cout << v[i] << " ";
	
	// Liberando a memoria alocada
	delete [] v;
	return 0;
}