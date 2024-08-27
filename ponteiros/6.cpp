#include <iostream>
using namespace std;

void soma(int x, int y, int &s1)
{
	s1 = x + y;
}

int main ()
{
	int x, y, s;
	
	x = 2;
	
	y = 3;
	
	soma(x, y, s);
	
	cout << "s = " << s << endl;
	
	return 0;
}
