#include <iostream>
using namespace std;

struct dado
{
	int idade;
	float peso;
};


int main ()
{
	dado *info = NULL;
	
	info = new dado;
	
	info->idade = 21;
	info->peso = 72.3;
	
	cout << "idade: " << info->idade << endl;
	cout << "peso: " << info->peso << endl;
	
	delete info;
	
	return 0;
}