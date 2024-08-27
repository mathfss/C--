#include <iostream>
#include <list>

using namespace std;

struct treenode
{
	int info;
	treenode* esq;
	treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr& p, int x)
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

treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento n�o encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub�rvore esquerda
		return tPesq(p->esq, x);
	else // procura na sub�rvore direita
		return tPesq(p->dir, x);
}

void emNivel(treenodeptr t)
{
	treenodeptr n;
	list<treenodeptr> q;
	if (t != NULL)
	{
		q.push_back(t);
		while (!q.empty())
		{
			n = *q.begin();
			q.pop_front();
			if (n->esq != NULL)
				q.push_back(n->esq);
			if (n->dir != NULL)
				q.push_back(n->dir);
			cout << n->info << " ";
		}
		cout << endl;
	}
}

void tDestruir(treenodeptr& arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

void posOrdem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << " ";
	}
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

void preOrdem(treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout << arvore->info << " ";
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

string Buscar(treenodeptr arvore, int elemento)
{
	if (arvore == NULL)
		return "Elemento nao encontrado";

	treenodeptr percursoEmOrdem = tPesq(arvore, elemento);
	treenodeptr percursoPosOrdem = tPesq(arvore, elemento);
	treenodeptr percursoPreOrdem = tPesq(arvore, elemento);

	if (percursoEmOrdem != NULL)
		return "Em Ordem";
	else if (percursoPosOrdem != NULL)
		return "P�s Ordem";
	else if (percursoPreOrdem != NULL)
		return "Pr� Ordem";
	else
		return "Elemento nao encontrado";
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

	int numero;
	cin >> numero;

	string MaisRapido = Buscar(arvore, numero);
	cout << MaisRapido << endl;

	tDestruir(arvore);

	return 0;
}
