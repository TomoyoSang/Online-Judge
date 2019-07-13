#include<iostream>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);


	auto i = 1,k=0;
		int mod = 0;
		int tmp = num;

		printf("%d", num);
		printf("%c", '=');
		
	for (i = 2; i <= tmp; i++)
	{
		mod = tmp % i;
		if (mod == 0)
		{
			while (tmp%i == 0)
			{
				k++;
				tmp /= i;
			}

		
			printf("%d", i);
			printf("%c", '(');
			printf("%d", k);
			printf("%c", ')');
			k = 0;

		}

	}
	

	return 0;
	



}