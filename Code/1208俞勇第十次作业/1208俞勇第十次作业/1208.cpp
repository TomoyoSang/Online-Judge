#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double mini = 0;
	double r, a;
	double cur = 0;
	while (cin >> r >> a)
	{
		cur = r * r*asin(sqrt(r*r - a * a)/r) - a * sqrt(r*r - a * a);
		mini = (cur <= mini) ? mini : cur;
	}
	printf("%.2f\n", mini);
	return 0;
}