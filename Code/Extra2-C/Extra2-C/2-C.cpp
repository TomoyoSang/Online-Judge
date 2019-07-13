#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int bilibili = 0;
	char s[120] = { 0 };
	int vowel[5] = { 0 };
	int T = 0;
	int counter = 0;
	while (cin >> T)
	{
		cin.get();
		for (; T > 0; T--)
		{
			if (!counter)
			{
				counter++;
			}
			else printf("\n");
			memset(vowel, 0, sizeof(vowel));
			memset(s, 0, sizeof(s));
			cin.getline(s, 106);
			//printf("%s", s);
			int i = strlen(s);
			for (int j = 0; j < i; j++)
			{
				if (s[j] == 'a')vowel[0]++;
				else if(s[j]=='e')vowel[1]++;
				else if(s[j]=='i')vowel[2]++;
				else if(s[j]=='o')vowel[3]++;
				else if(s[j]=='u')vowel[4]++;
			}
			printf("%c:%d\n", 'a', vowel[0]);
			printf("%c:%d\n", 'e', vowel[1]);
			printf("%c:%d\n", 'i', vowel[2]);
			printf("%c:%d\n", 'o', vowel[3]);
			printf("%c:%d\n", 'u', vowel[4]);
		}

	}



	return 0;
}