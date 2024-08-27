#include <bits/stdc++.h>

using namespace std;

int main ()
{
	int n;
	int t;
	char palavra[50];
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> palavra;
		cin >> n;
		
		for (int j = 0; j < strlen(palavra); j++)
		{
			palavra[i] = palavra[i] - n;
			
			if (isalpha(palavra[j]) == false)
			{
				palavra[j] = palavra[j] + 26;
			}
		}
		
		cout << palavra << endl;
		
	}
	
	
	return 0;
}