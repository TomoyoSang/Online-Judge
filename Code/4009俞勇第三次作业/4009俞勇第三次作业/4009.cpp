#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char Cstring[105] = { 0 };
char Sstring[105] = { 0 };
char filter[105] = { 0 };
int n = 0,counter=0;
int factors[22] = { 0 };
int cmp = 0;
bool flag = 1;
void factor(int n)
{
	
	counter = 0;
	for (int i = 2; i <= n; i++)
	{
		if (n%i == 0)
		{
			factors[counter] = i;
			counter++;
		}
			
	}
	return;
}

bool Translate(int i)
{
	memset(filter, 0, sizeof(filter));
	int q = 0,j=0,k=0;
	for ( k = 0; k < i; k++)
	{
		for ( j = k; j < n; j += i)
		{
			filter[q] = Cstring[j];
			q++;
		}

	}
	filter[q] = '\0';

	cmp = strcmp(filter, Sstring);
	if (cmp == 0)return 1;
	return 0;
}

int main()
{
	cin >> Cstring;
	cin >> Sstring;
	
	n = strlen(Sstring);
	/*cmp = strcmp(Cstring, Sstring);
	if (cmp == 0)
	{
		cout << n;
		return 0;
	}*/

	factor(n);
	//for (int i = 0; i < 22; i++)cout << factors[i];
	
	for (int i = 0; factors[i] != 0; i++)
	{
		flag=Translate(factors[i]);
		if (flag) 
		{
			cout << factors[i]; 
			break;
		}

	}
	if (!flag)cout <<"No Solution";
	
	return 0;



}