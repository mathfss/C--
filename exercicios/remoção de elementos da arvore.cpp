#include<iostream>
using namespace std;

struct treenode {
    int info; // raiz
    treenode *esq; // sub-arvore esquerda
    treenode *dir; //sub - arvore direita
};

typedef treenode *treenodeptr; // definindo uma variavel tipo treenode

void tInsere(treenodeptr &p, int x) {
    if(p==NULL) { // insere na raiz pq vai estar vazio
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else
    if(x<p->info) // insere a esquerda
        tInsere(p->esq,x);
    else // insere a direita
        tInsere(p->dir,x);
}

treenodeptr tPesq(treenodeptr p, int x){

    if (p == NULL) // elemento não encontrado
        return NULL;
    else if (x == p->info) // elemento encontrado na raiz
        return p;
    else
        // procura na sub ´arvore esquerda
    if (x < p->info)
        return tPesq(p->esq,x);
        // procura na sub ´arvore direita
    else
        return tPesq(p->dir,x);
}

treenodeptr tMenor(treenodeptr &raiz)
{
    treenodeptr t;
    t = raiz;
    if (t->esq == NULL) // encontrou o menor valor
    {
        raiz = raiz->dir;
        return t;
    }
    else // continua a busca na sub?arvore esquerda
        return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x)
{
    treenodeptr p;
    if (raiz == NULL) // ?arvore vazia
        return 1;
    if (x == raiz->info)
    {
        p = raiz;
        if (raiz->esq == NULL) // a raiz n~ao tem filho esquerdo
            raiz = raiz->dir;
        else {
			if (raiz->dir == NULL) // a raiz n~ao tem filho direito
	            raiz = raiz->esq;
	        else // a raiz tem ambos os filhos
	        {
	            p = tMenor(raiz->dir);
	            raiz->info = p->info;
	        }
		}
        delete p;
        return 0;
    }
    else if (x < raiz->info)
        return tRemove(raiz->esq, x);
    else
        return tRemove(raiz->dir, x);
}

void emOrdem (treenodeptr arvore)
{
    if (arvore != NULL)
    {
        cout << arvore->info << " ";
        emOrdem(arvore->esq);
        emOrdem(arvore->dir);
    }
}
int main() {
    treenodeptr arvore = NULL; // começa com NULL


    int x; // elemento a ser inserido
    cin >> x;
    while(x!=0) {
            tInsere(arvore,x);
            cin >> x;
    }
    int y;
    cin >> y;
    //remocao do elemento pesquisado, se encontrado:
    if(tPesq(arvore,y)!=NULL) {
        cout << "Elemento " << y << " encontrado!" << endl;
        tRemove(arvore,y); 
    }
    else {
		cout << "Elemento nao encontrado!" << endl;
	}
	
	emOrdem(arvore); 


    return 0;
}