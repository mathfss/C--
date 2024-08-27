#include <iostream>
#include <iomanip>

using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};

typedef treenode *treenodeptr;

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}

void tDestruir(treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int Soma(treenodeptr arvore)
{
	if (arvore == NULL)
		return 0;

	return arvore->info + Soma(arvore->esq) + Soma(arvore->dir);
}

int Contar(treenodeptr arvore)
{
	if (arvore == NULL)
		return 0;

	return 1 + Contar(arvore->esq) + Contar(arvore->dir);
}

double Media(treenodeptr arvore)
{
	int soma = Soma(arvore);
	int count = Contar(arvore);

	if (count == 0)
		return 0;

	return (double)soma / count;
}

int main()
{
	treenodeptr arvore = NULL;
	int n;

	while (true)
	{
		cin >> n;
		if (n == -1)
			break;

		tInsere(arvore, n);
	}

	double media = Media(arvore);
	cout << fixed << setprecision(2);
	cout << media << endl;

	tDestruir(arvore);

	return 0;
}
