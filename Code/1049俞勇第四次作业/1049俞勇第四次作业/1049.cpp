#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int trains[1020] = { 0 };
int orders[1020] = { 0 };

int main() 
{
	int T = 0;
	scanf("%d", &T);
	int N, M;
	for (; T > 0; T--)
	{
		int j = 0, i = 0;
		memset(trains, 0, sizeof(trains));
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &orders[i]);
			
		}

		i = 0;
		int counter = 0;
		
		bool flag = 1;
	

		while (j < N)
		{
			
			if (i == orders[j])
			{
				i++;
				j++;
			}
			else if (counter != 0)
			{
				if (trains[counter - 1] == orders[j])
				{
					j++;
					counter--;
				}
				else if (trains[counter - 1] > orders[j])
				{
					printf("NO\n");
					flag = 0;
					break;
				}
				else if (trains[counter - 1] < orders[j])
				{
					trains[counter] = i;
					counter++;
					i++;
				}
			
			}
			else 
			{
				trains[counter] = i;
				counter++;
				i++;
			}
			
			if (i == N)
			{
				if (j == N)break;
				else if (counter > 0 && trains[counter - 1] == orders[j])
				{
					j++;
					counter--;
				}
				else
				{
					printf("NO\n");
					flag = 0;
				}
			}
				
			if (counter > M)
			{
				printf("NO\n");
				flag = 0;
				break;
			}
				
			
		}
		if (flag)printf("YES\n");

		
	}

	return 0;
}