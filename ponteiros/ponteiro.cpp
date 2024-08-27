#include <iostream>
#include <iomanip>

using namespace std;

struct ficha
{
	int n1, n2, n3, n4;
};

int main ()
{
	int n;
	cin >> n;
	float soma = 0;
	float media;

	ficha *avaliado = NULL;

	avaliado = new ficha[50];

	for (int i = 0; i < n; i++)
	{
		cin >> avaliado[i].n1 >> avaliado[i].n2 >> avaliado[i].n3 >> avaliado[i].n4;
	}

	for (int i = 0; i < n; i++)
	{
		soma = soma + avaliado[i].n1 + avaliado[i].n2 + avaliado[i].n3 + avaliado[i].n4;
	}

	media = soma / (4 * n);

	cout << fixed << setprecision(2);
	cout << media;

	return 0;
}
