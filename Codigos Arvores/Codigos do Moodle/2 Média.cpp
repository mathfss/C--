#include <iostream>
#include <list>
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

float media(treenodeptr arvore)
{
	if (arvore == NULL)
		return 0.0;

	float soma = 0.0;
	int contagem = 0;

	list<treenodeptr> fila;
	fila.push_back(arvore);

	while (!fila.empty())
	{
		treenodeptr no = fila.front();
		fila.pop_front();

		soma += no->info;
		contagem++;

		if (no->esq != NULL)
			fila.push_back(no->esq);
		if (no->dir != NULL)
			fila.push_back(no->dir);
	}

	return soma / contagem;
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

	float media_arvore = media(arvore);
	
	cout << fixed << setprecision(2);
	cout << "Media: " << media_arvore << endl;
	
	tDestruir(arvore);

	return 0;
}