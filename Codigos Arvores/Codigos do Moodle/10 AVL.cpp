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

treenodeptr tPesq(treenodeptr p, int x, int &count)
{
	count++;
	if (p == NULL) // elemento não encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
		return p;
	else if (x < p->info) // procura na subárvore esquerda
		return tPesq(p->esq, x, count);
	else // procura na subárvore direita
		return tPesq(p->dir, x, count);
}

int altura(treenodeptr p)
{
	if (p == NULL)
		return 0;
	return 1 + max(altura(p->esq), altura(p->dir));
}

void rotacaoDireita(treenodeptr &p)
{
	treenodeptr q = p->esq;
	p->esq = q->dir;
	q->dir = p;
	p = q;
}

void rotacaoEsquerda(treenodeptr &p)
{
	treenodeptr q = p->dir;
	p->dir = q->esq;
	q->esq = p;
	p = q;
}

void rotacaoDuplaDireita(treenodeptr &p)
{
	rotacaoEsquerda(p->esq);
	rotacaoDireita(p);
}

void rotacaoDuplaEsquerda(treenodeptr &p)
{
	rotacaoDireita(p->dir);
	rotacaoEsquerda(p);
}

void balancearAVL(treenodeptr &p)
{
	int fatorBalanceamento = altura(p->esq) - altura(p->dir);

	if (fatorBalanceamento > 1) // Subárvore esquerda é mais alta
	{
		if (altura(p->esq->esq) >= altura(p->esq->dir))
			rotacaoDireita(p);
		else
			rotacaoDuplaDireita(p);
	}
	else if (fatorBalanceamento < -1) // Subárvore direita é mais alta
	{
		if (altura(p->dir->dir) >= altura(p->dir->esq))
			rotacaoEsquerda(p);
		else
			rotacaoDuplaEsquerda(p);
	}
}

void tInsereAVL(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if (x < p->info) // insere na subarvore esquerda
	{
		tInsereAVL(p->esq, x);
		balancearAVL(p);
	}
	else // insere na subarvore direita
	{
		tInsereAVL(p->dir, x);
		balancearAVL(p);
	}
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

int main()
{
	treenodeptr arvoreNormal = NULL;
	treenodeptr arvoreAVL = NULL;

	int n;
	cin >> n;
	while (n != 0)
	{
		tInsere(arvoreNormal, n);
		tInsereAVL(arvoreAVL, n);
		cin >> n;
	}

	int x;
	cin >> x;

	int contadorNormal = 0;
	tPesq(arvoreNormal, x, contadorNormal);

	int contadorAVL = 0;
	tPesq(arvoreAVL, x, contadorAVL);

	cout << "Arvore normal: " << contadorNormal << endl;
	cout << "AVL: " << contadorAVL << endl;

	tDestruir(arvoreNormal);
	tDestruir(arvoreAVL);

	return 0;
}
