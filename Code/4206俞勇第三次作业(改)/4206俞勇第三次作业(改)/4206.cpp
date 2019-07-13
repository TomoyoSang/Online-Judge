#include <iostream>
#include <cstdio>

using namespace std;


int n = 0, m = 0;
int cur = 0;
char s = 0;
int  N[2000][2000] = { 0 };
int qianzhui[2000][2000] = { 0 };
int curn = 0, curm = 0;
int min1 = 1000000, min2 = 0;
int  tryit(int p)
{
	if (n%p != 0)curn = (n / p + 1)*p;
	else curn = n;
	if (m%p != 0)curm = (m / p + 1)*p;
	else curm = m;

	min2 = 0;
	for (int j = p; j <= curn ; j += p)
	{
		for (int k = p; k <= curm ; k += p)
		{
			cur = qianzhui[j][k] - qianzhui[j - p][k] - qianzhui[j][k - p] + qianzhui[j - p][k - p];
			min2 += (cur>p*p-cur)?(p*p-cur):cur;
		}
	}

	return min2;
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{

			s = cin.get();
			while ((s != '0') && (s != '1'))
				s = cin.get();
			N[i][j] = int(s - '0');
		}
	}
	
	int black = 0;
	int big = (n > m) ? n : m;
	for (int i = 1; i <2000; i++)
	{
		for (int j = 1; j < 2000; j++)
		{
			black = 0;
			if (N[i][j] == 1)black = 1;
			
			 qianzhui[i][j] = qianzhui[i][j - 1] + qianzhui[i - 1][j] - qianzhui[i - 1][j - 1]+black;

		}
	}
	
		
			
	
	int can1 = 0, can2 = 0;
	can1 = tryit(2);
	
	for (int i = 3; i <= big; i+=2)
	{
		can2 = tryit(i);
		
		if (min1 > can2)min1 = can2;
	}
	
	if(min1<can1)
	printf("%d", min1);
	else printf("%d", can1);
	return 0;
}