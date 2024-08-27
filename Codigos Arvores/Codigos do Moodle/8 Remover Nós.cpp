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
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na sub?arvore esquerda
		return tPesq(p->esq, x);
	else // procura na sub?arvore direita
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


void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

void posOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{

		posOrdem(arvore->esq);
		posOrdem(arvore->dir);

		cout << arvore->info << " ";
	}
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}

void preOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		cout  << arvore->info << " ";
		preOrdem(arvore->esq);
		preOrdem(arvore->dir);
	}
}

treenodeptr tRemove(treenodeptr p, int x)
{
	if (p == NULL) 
		return NULL;

	if (x < p->info) 
		p->esq = tRemove(p->esq, x);
	else if (x > p->info) 
		p->dir = tRemove(p->dir, x);
	else 
	{
		if (p->esq == NULL && p->dir == NULL) 
		{
			delete p;
			p = NULL;
		}
		else if (p->esq == NULL) 
		{
			treenodeptr temp = p;
			p = p->dir;
			delete temp;
		}
		else if (p->dir == NULL) 
		{
			treenodeptr temp = p;
			p = p->esq;
			delete temp;
		}
		else 
		{
			treenodeptr temp = p->dir;
			while (temp->esq != NULL)
				temp = temp->esq;
			p->info = temp->info;
			p->dir = tRemove(p->dir, temp->info);
		}
	}
	return p;
}

int main()
{
	treenodeptr arvore = NULL;
	int n;
	int cont = 0;

	cin >> n;
	while (n != 0)
	{
		tInsere(arvore, n);
		cin >> n;
		cont++;
	}

	int x;
	cin >> x;

	for (int i = 0; i < cont; i++)
		tRemove(arvore, x);

	emOrdem(arvore);

	return 0;
}
