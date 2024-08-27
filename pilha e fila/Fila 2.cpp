#include <iostream>
#include <list>
using namespace std;

int main ()
{
	list<int> fila; // declarar lista
	int x;
	
	// Inserindo dados na fila
	fila.push_back(1);
	fila.push_back(2);
	fila.push_back(3);
	fila.push_back(4);
	
	// Removendo e mostrando elementos da fila
	
	while (!fila.empty())
	{
  		x = *fila.begin();
  		cout << x << endl;
  		fila.pop_front();
	}
	
	return 0;
}