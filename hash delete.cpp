#include <iostream>
#include <cmath>

using namespace std;

struct dado
{
	int k;
	int status;
};

int hash_aux(int k, int m)
{
	int hx, hx1 ;
	hx = k % m;

	if(hx < 0)
	{
		hx1 = hx + m;
		return hx1;
	}
	else
		return hx;
}

int hash1(int k, int i, int m)
{
	int hash ;
	hash = ((hash_aux(k, m) + i) % m);
	return hash;


}

int hash_insert(dado T[], int m, int k)
{
	int i = 0;
	int j;
	do
	{
		j = hash1(k, i, m);
		if (T[j].status != 1)
		{
			T[j].k = k;
			T[j].status = 1;
			return j;
		}
		else
			i ++;
	}
	while( i != m);
	return -1;

}

int hash_search(dado T[], int m, int k)
{
	int i = 0;
	int j;

	do
	{
		j = hash1(k, i, m);
		if (T[j].k == k)
			return j;
		else
			i++;
	}
	while(T[j].status != 0 && i < m);
	return -1;
}

int hash_remove(dado T[], int m, int k)
{
	int j;
	j = hash_search(T, m, k);

	if (j != -1)
	{
		T[j].status = 2;
		T[j].k = -1;
		return 0;
	}

	else
		return -1;
}

int main()
{
	int m;
	int k;
	dado T[100];
	int i;

	cin >> m ;

	for(i = 0; i < m; i++)
	{
		T[i].k = -1;
		T[i].status = 0;
	}

	cin >> k;

	while(k != 0)
	{
		hash_insert(T, m, k);
		cin >> k;
	}

	cin >> k;
	hash_remove(T, m, k);

	for(i = 0; i < m; i++)
	{
		cout << T[i].k << " ";
	}

	return 0;
}
