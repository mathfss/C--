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
	int i = 0;
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
			cout << i << ":" << n->info << endl;
			i++;
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



int main()
{

	treenodeptr arvore = NULL;
	float t, v, e, o;
	int p;
	int n=7;
	cin >> p;

	for (int i = 0; i < p; i++)
	{
		cin >> v;
		cin >> e;
		cin >> o;
		
		t = v * e * n * e * n *o;

		tInsere(arvore, t);
	}
	
	emNivel(arvore);
	
	tDestruir(arvore);

	return 0;
}
