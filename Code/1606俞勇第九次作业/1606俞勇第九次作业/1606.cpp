#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int N[51][51] = { 0 };
int lu[2500][2] = { 0 };
int wenhao[2500][2] = { 0 };
int main()
{
	char s;
	scanf("%d %d", &n, &m);
	int counter1 = 0, counter2 = 0;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%c", &s);
			if (s == '.')
			{
				N[i][j] = 1;
				lu[counter1][0] = i;
				lu[counter1][1] = j;
				counter1++;
			}
			else if (s == '?')
			{
				N[i][j] = counter2 + 2;
				wenhao[counter2][0] = i;
				wenhao[counter2][1] = j;
				counter2++;
			}
		}
	}




}