#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int m, n;
int strings[10002] = { 0 };

int operators[10000][3] = { 0 };
int ileft = 0, iright = 0, counter = 0;
void judging(int i)
{
		counter = 0;
		ileft = operators[i][0];
		iright = operators[i][1];
		int q = operators[i][2];
		if (q > iright || q < ileft)
		{
			if (i != 0)printf("\n");
			printf("%s", "Yes");
		}

		else
		{
			for (int j = ileft; j <= iright; j++)
			{
				if (strings[j - 1] < strings[q-1])counter++;
			}
			if (i != 0)printf("\n");
			if (counter + ileft == q)printf("%s", "Yes");
			else printf("%s", "No");
			return;
		}
	


	return;
}

int main()
{
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &strings[i]);
	}
	

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &operators[i][0], &operators[i][1], &operators[i][2]);
		//cin >> operators[i][0] >> operators[i][1] >> operators[i][2];
	}
	
	for (int i = 0; i < m; i++)
	{
		judging(i);
	}
	
	


	return 0;


}