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
	if (p == NULL)   // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info)     // insere na subarvore esquerda
	{
		tInsere(p->esq, x);
	}
	else     // insere na subarvore direita
	{
		tInsere(p->dir, x);
	}
}

int Profundidade(treenodeptr p)
{
	if (p == NULL)   // árvore vazia, profundidade é 0
	{
		return 0;
	}
	else
	{
		int esqProfundidade = Profundidade(p->esq);
		int dirProfundidade = Profundidade(p->dir);
		return 1 + max(esqProfundidade, dirProfundidade);
	}
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

	int profundidade = Profundidade(arvore);
	cout << profundidade << endl; // -1??

	return 0;
}
