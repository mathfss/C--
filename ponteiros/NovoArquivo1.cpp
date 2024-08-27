#include <iostream>
using namespace std;

int main ()
{
	int x, y;
	int *p, *r, *q;
	int soma;
	
	x = 2;
	y = 3;
	
	p = &x;
	r = &soma;
	
	*r = 0;
	*r = *p + *r;
	
	p = &y;
	
	*r = *p + *r;
	
	cout << "soma = " << soma << endl;
	
	return 0;
}