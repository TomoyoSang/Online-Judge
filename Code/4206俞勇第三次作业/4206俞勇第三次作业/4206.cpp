#include <iostream>
#include <cstdio>

using namespace std;

int n = 0, m = 0;
int cur = 0;
char s = 0;
int  N[2000][2000] = { 0 };
int tryit(int p)
{
	//²¹È«Í¼Æ¬±ß½ç
	int curn , curm ;
	if (n%p != 0)curn = (n / p + 1)*p;
	else curn = n;
	if (m%p != 0)curm = (m / p + 1)*p;
	else curm = m;
	int black = 0, white = 0,min1=0,min2=0;
	for (int i = 0; i < curn; i+=p)
	{
		
		for (int j = 0; j < curm; j+=p)
		{
			
			black = 0; white = 0;
			
			for (int k = i; k < i + p; k++)
			{

				for (int x = j; x < j + p; x++)
				{
					if (N[k][x] == 0)white++;
					else black++;
				}
			}
			min1 = (black > white) ? white : black;
			min2 += min1; //cout << min2 << endl;
		}
	}
	return min2;

}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			s = cin.get();
			while((s!='0')&&(s!='1'))
				s = cin.get();
			N[i][j] = int (s-'0');
		}
	}

	int big = (n > m) ? m : n;
	//int can = tryit(1);
	//cout << can << endl;
	int can1=tryit(2);
	//cout << can1;
	//cout << can1 << endl;
	int can2 = 1000000;
	for (int i = 3; i <= big; i += 2)
	{
		
		cur=tryit(i);
		if (can2 > cur)can2 = cur;
	}
	//cout << can2 << endl;
	if (can1 < can2)printf("%d", can1);
	else printf("%d", can2);

	return 0;
}

/*for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
		{
			//s = cin.get();
			//N[i][j] = s;
			cout << N[i][j];
		}
	}*/