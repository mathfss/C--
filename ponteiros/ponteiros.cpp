#include <iostream>
#include <iomanip>

using namespace std;

struct aluno
{
	int notas;
	int media;	
};

int main ()
{
	aluno *avaliado = NULL;
	
	avaliado = new aluno[5];
	
	aluno *mediaf = NULL;
	mediaf = new aluno;
	
	
	for (int i=0; i < 4; i++)
	{
		cin >> avaliado[i].notas;
	}
	
	for (int i=0; i < 4; i++)
	{
		 mediaf->media = (mediaf->media + avaliado[i].notas) / 4;
	}
	
	cout << fixed << setprecision(2);
	
	cout << mediaf->media;
	
	return 0;	
}