#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main()
{
	int n, a, b, x1, x2, y1, y2,imax;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d%d%d", &a, &b, &x1, &y1, &x2, &y2);
		int len = 0, wid = 0;
		len = abs(floor(double(x1 + y1) / (2 * a) )- floor(double(x2 + y2) / (2 * a)));
		wid = abs(floor(double(x1 - y1) / (2 * b)) - floor(double(x2 - y2) / (2 * b)));
		imax = (len > wid) ? len : wid;
		
		printf("%d\n", imax);
	}

	return 0;

}