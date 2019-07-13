#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char N[103][103] = { 0 };
int num[103] = { 0 };
int main()
{
	int n;
	scanf("%d", &n);
	
	char s[100] = { 0 };
	cin.getline(s, 100, '\n');
	for (int i = 0; i < n; i++)
	{
		cin.getline(s, 100, '\n');
		while (strcmp(s, "") == 0)cin.getline(s, 100, '\n');
		strcpy(N[i], s);
	}
	for (int i = 0; i < n; i++)
	{
		num[i] = strlen(N[i]) ;
	}
	int x = 0, y = 0;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		strcpy(N[y-1] + num[y-1], N[x-1]);
		num[y-1] += (num[x-1]);
		num[x-1] = 0;	
	}

	for (int i = 0; i < n; i++)
	{
		if (num[i] != 0)
		{
			for (int j = 0; j < strlen(N[i]); j++)
			{
				
				if (N[i][j] >= '0' && N[i][j] <= '9')
				{
					printf("%d", N[i][j] - '0');
					printf(" ");
				}
			}
			printf(" ");
		}
	}
	return 0;
}