#include<iostream>
using namespace std;

struct treenode
{
	int info; // raiz
	treenode *esq; // sub-arvore esquerda
	treenode *dir; //sub - arvore direita
};

typedef treenode *treenodeptr; // definindo uma variavel tipo treenode

void tInsere(treenodeptr &p, int x)
{
	if(p == NULL) // insere na raiz pq vai estar vazio
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if(x < p->info) // insere a esquerda
		tInsere(p->esq, x);
	else // insere a direita
		tInsere(p->dir, x);
}

int tPesq(treenodeptr p, int x)
{
	if (p == NULL)
		return 0;
	else if (x == p->info)
		return 1;
	else if (x < p->info)
		return tPesq(p->esq, x);
	else
		return tPesq(p->dir, x);
}

int main()
{
	treenodeptr arvore = NULL; // começa com NULL


	int x; // elemento a ser inserido
	cin >> x;
	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	int n; // numero para ser pesquisado
	cout << "Digite o numero que deseja pesquisar: ";
	cin >> n;
	if (tPesq(arvore, n))
		cout << "Elemento encontrado" << endl;
	else
		cout << "Elemento nao encontrado" << endl;

	return 0;
}
