#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int K = 0;
	scanf("%d", &K);
	double s = 0;
	double n = 0;
	while (s <= K)
	{
		n++;
		s += (double)(1 / n);
	}

	printf("%.f", n);
	return 0;
}