#include <iostream>
#include <cstdio>

//********************
using namespace std;

int main()
{
	int n;
	double sum = 0;
	int cur = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &cur);
		if (cur >= 95)sum += 4.3;
		else if (cur >= 90)sum += 4.0;
		else if (cur >= 85)sum += 3.7;
		else if (cur >= 80)sum += 3.3;
		else if (cur >= 75)sum += 3.0;
		else if (cur >= 70)sum += 2.7;
		else if (cur >= 67)sum += 2.3;
		else if (cur >= 65)sum += 2.0;
		else if (cur >= 62)sum += 1.7;
		else sum += 1.0;
	}
	sum /= n;
	printf("%.2f", sum);
		return 0;


}