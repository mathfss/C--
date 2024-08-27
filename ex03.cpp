#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
	setlocale(LC_ALL, "portuguese");
	int equipes, i, o = 0;
	double nf[10], acertos, erros, tempo, maior = 0;
	char nome[10][31], vencedor[10][31];
	cout << "Insira o número de equipes(1-10)" << endl;
	do
		cin >> equipes;
	while(equipes < 1 || equipes > 10);
	for(i = 0; i < equipes; i++)
	{
		cout << "Insira o nome da equipe" << endl;
		cin.ignore();
		cin.getline(nome[i], 31);
		cout << "Insira a quantidade de acertos" << endl;
		cin >> acertos;
		cout << "Insira a quantidade de erros" << endl;
		cin >> erros;
		cout << "Insira o tempo usado(em minutos)" << endl;
		cin >> tempo;
		nf[i] = ((5 * acertos) - (2 * erros)) + 1 / tempo;
		if(nf[i] >= maior)
		{
			maior = nf[i];
			strcpy(vencedor[o], nome[i]);
			o++;
		}

	}
	cout << "Listagem Final:" << endl;
	for(i = 0; i < equipes; i++)
	{
		cout << nome[i] << " - " << nf[i] << " ptos." << endl;
	}





	cout << "Maior pontuação: " << maior << " ptos." << endl;
	cout << "Equipe(s) vencedora(s): ";
	for(i = 0; i < o; i++)
	{
		cout << vencedor[i] << "\t";
	}
	return 0;
}
