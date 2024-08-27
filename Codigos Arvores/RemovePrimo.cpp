#include <iostream>
#include <list>
#include <cmath>

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

bool Primo(int x)
{
	if (x <= 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

treenodeptr removePrimo(treenodeptr p)
{
	if (p == NULL)
		return NULL;

	p->esq = removePrimo(p->esq);
	p->dir = removePrimo(p->dir);

	if (Primo(p->info))
	{
		treenodeptr temp = p;
		p = NULL;
		delete temp;
	}

	return p;
}

void emOrdem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}

int main()
{
	treenodeptr arvore = NULL;
	int n;

	while (true)
	{
		cin >> n;
		if (n < 0)
			break;
		tInsere(arvore, n);
	}

	arvore = removePrimo(arvore);
	emOrdem(arvore);
	cout << endl;
	
	tDestruir(arvore);

	return 0;
}
