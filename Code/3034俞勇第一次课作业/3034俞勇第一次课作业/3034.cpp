#include<iostream>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int tmp, gap = 0;
	int i = 2;
	int mod = 0;
	bool flag = 0;
	for (i = 2; i < num; i++)
	{
		mod = num % i;
		if (mod == 0) { flag = 1; break; }

	}
	if (flag == 0)
	{
		printf("%d", 0); return 0;
	}

	for (tmp = num; tmp >= 1; tmp--)
	{
		flag = 0;
		
		for (i = 2; i < tmp; i++)
		{
			mod = tmp % i;
			if (mod == 0) 
			{
				flag = 1;
				gap++; break;
			}
			
		}
		if (flag == 0)break;
	}

	for (tmp = num;  ; tmp++)
	{
		flag = 0;

		for (i = 2; i < tmp; i++)
		{
			mod = tmp % i;
			if (mod == 0)
			{
				flag = 1;
				gap++; break;
			}

		}
		if (flag == 0)break;

	}

	printf("%d", gap);

	return 0;

}


