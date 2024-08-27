#include <iostream>

using namespace std;

void fibonacci(int n, int* resultado)
{
	int fib1 = 0, fib2 = 1, fib;
	for (int i = 2; i <= n; i++)
	{
		fib = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib;
	}
	*resultado = fib2;
}

int main()
{
	int n;
	int fib;
	
	cin >> n;
	
	fibonacci(n, &fib);
	
	cout << fib << endl;
	
	return 0;
}
