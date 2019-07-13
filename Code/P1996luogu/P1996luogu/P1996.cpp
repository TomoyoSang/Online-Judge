#include <stdio.h>
#include <stdlib.h> 
int peoples[100];
int main(void)
{
	int persons = 0;
	int m;
	scanf("%d", &persons);
	scanf("%d", &m);
	int i;
	for (i = 1; i <= persons; i++)
	{
		peoples[i] = i;
	}
	i = 1;
	int j = 0;
	int rest = persons;
	while (rest != 0)
	{
		if (i > persons)
		{

			i %= persons;
		}
		if (peoples[i] == 0) 
		{
			i++;
			continue;
		}
		if (++j%m == 0 && rest > 1)
		{
			printf("%d ", peoples[i]);
			peoples[i] = 0;
			rest--;
		}
		else if (rest == 1)
		{
			printf("%d", peoples[i]);
			rest--;
		}
		i++;
	}
	
	return 0;
}