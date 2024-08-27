#include <iostream>
#include <list>

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
	if (p == NULL)
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info)
		tInsere(p->esq, x);
	else
		tInsere(p->dir, x);
}

int Folhas(treenodeptr arvore)
{
	if (arvore == NULL)
		return 0;
	if (arvore->esq == NULL && arvore->dir == NULL)
		return 1;
	return Folhas(arvore->esq) + Folhas(arvore->dir);
}

int NaoFolhas(treenodeptr arvore)
{
	if (arvore == NULL || (arvore->esq == NULL && arvore->dir == NULL))
		return 0;
	return 1 + NaoFolhas(arvore->esq) + NaoFolhas(arvore->dir);
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

	int folhas = Folhas(arvore);
	int naofolhas = NaoFolhas(arvore);

	cout << "Quantidade de folhas: " << folhas << endl;
	cout << "Quantidade de nao folhas: " << naofolhas << endl;

	tDestruir(arvore);

	return 0;
}
