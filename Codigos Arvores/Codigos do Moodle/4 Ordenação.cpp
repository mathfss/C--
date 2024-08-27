#include <iostream>
#include <list>

using namespace std;


struct treenode
{
	int info;
	int I;
	treenode *esq;
	treenode *dir;

};


typedef treenode *treenodeptr;


void tInsere(treenodeptr &p, float x, int i)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->I = i;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x, i);
	else // insere na subarvore direita
		tInsere(p->dir, x, i);
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

void emOrdem (treenodeptr arvore, int min, int max)
{
	
	if (arvore != NULL)
	{
		emOrdem(arvore->esq, min, max);
		if(arvore->info >= min && arvore->info <= max) {
			cout << arvore->I << ":" << arvore->info << endl;}
		else {
		}
		emOrdem(arvore->dir, min, max);
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
	float p;
	float n = 7;
	int tmin, tmax;

	cin >> p;

	for (int i = 0; i < p; i++)
	{
		cin >> v;
		cin >> e;
		cin >> o;

		t = v * e * n * e * n * o;

		tInsere(arvore, t, i);
	}
	
	cin >> tmin >> tmax;

	emOrdem(arvore, tmin, tmax);

	tDestruir(arvore);

	return 0;
}
