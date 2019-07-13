#include <iostream>
#include <cstdio>

using namespace std;

int A[1003] = { 0 };
int main()
{
	int n;
	scanf("%d", &n);
	int value = 0;
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &value);
		if (A[value] != 0)counter++;
		else A[value] = 1;
	}
	printf("%d\n", n - counter);
	for (int i = 1; i <= 1000; i++)
	{
		if (A[i])printf("%d ", i);
	}
	
	return 0;
}