#include <iostream>
#include <cstring>
using namespace std;

void cmp(char*, char*);
char Strings[1000][1000];
char filter[1000];
int counter = 0;
int main()
{
	int quantity = 0;
	cin >> quantity;
	int i = 0;

	char c;

	char Sample[103];
	c = cin.get();
	while (c != '-')c = cin.get();
	cin >> Sample;
	
	for (i = 0; i < quantity; i++)
	{
		c = cin.get();
		while (c != '-')c = cin.get();
		cin >> Strings[i];
	}

	int m = 0, n = 0;
	m = strlen(Sample);
	Sample[m - 1] = '\0';
	for (i = 0; i < quantity; i++)
	{
		m = strlen(Strings[i]);
		Strings[i][m - 1] = '\0';
	}

	for (i = 0; i < quantity; i++)
	{
		cmp(Sample, Strings[i]);
	}

	cout << counter;
	return 0;
}


void cmp(char* Sample, char*  s)
{
	int i = 0;
	int k = strlen(Sample);
	int j = strlen(s);
	for (i = 0; i < j; i++)
	{
		filter[i] = s[j - i-1];

	}
	filter[i++] = '\0';

	bool flag = 0;
	int condition = 0;
	
	if (k != j)return;
	else
	{
		for (i = 0; i < j; i++)
		{

			s[i + j] = '\0';
			condition = strcmp(Sample, s + i);
			if (condition == 0)
			{
				counter++; return;
			}
			else

				s[i + j] = s[i];

		}

		for (i = 0; i < j; i++)
		{

			filter[i + j] = '\0';
			condition = strcmp(Sample, filter + i);
			if (condition == 0)
			{
				counter++; return;
			}
			else

				filter[i + j] = filter[i];

		}
		
		


	}

}

