#include <iostream>

using namespace std;

int menor (int *vetor, int N)
{
	int menorzin=100000;
	
	for (int i=0; i < N; i++)
	{
		if (vetor[i] < menorzin)
			menorzin = vetor[i];			
	} 

	return menorzin;
}

int maior (int *vetor, int N)
{
	int maior=0;
	
	for (int i=0; i < N; i++)
	{
		if (vetor[i] > maior)
			maior = vetor[i];
	}
	
	return maior;
}

int main ()
{
	int N;
	int vet[50];
	
	cin >> N;
	
	for (int i=0; i < N; i++)
	{
		cin >> vet[i];
	}
	
	cout << "menor: " << menor(vet, N) << endl;
	cout << "maior: " << maior(vet, N) << endl;
	
	
	return 0;
}