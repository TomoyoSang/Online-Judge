#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char buff[100009] = { 0 };
int char_total[30] = { 0 };
int main()
{
	int bilibili = 0;
	while ( gets(buff))
	{
		memset(char_total, 0, sizeof(char_total));
		int len = strlen(buff);
		for (int i = 0; i < len; i++)
		{
			if (buff[i] >= 'a'&&buff[i] <= 'z')
			{
				char_total[buff[i] - 'a']++;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			printf("%c:", 'a' + i);
			printf("%d\n",char_total[i]);
		}
		printf("\n");
		
	}
	


	return 0;
}