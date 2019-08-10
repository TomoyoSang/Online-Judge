#include <iostream>
#include <cstdio>

using namespace std;

int flag = 0;
double  N[100000] = { 0 };
int n;
int k = 0;
double tmp = 0;

int iremain(double i)
{
	i = 2 * i;
	int num = k;
	double mindis = 10000;
	double Edge = -10000000;
	for (int j = 0; j < n; j++)
	{
		if (Edge >= N[j])
		{
			tmp = Edge - N[j];

			mindis = (tmp < mindis) ? tmp : mindis;
			continue;
		}

		else
		{
			Edge = N[j] + i;
			num--;

		}
	}


	if (num > 0)return 1;
	else if (num < 0)return -1;
	else if (num == 0)
	{
		if (mindis > 0)return 1;
		else return 0;
	}


}
void Divide(double left,double right )
{
	if (right - left < 0.0000001) {
		printf( "%.6lf",right); return;
	}
	double mid = (left + right) / 2;
	
	
	flag=iremain(mid);

	if (flag>0)
	{
		Divide(left, mid);
	}
	else if (flag < 0)
	{
		Divide(mid, right);
	}
	else {
		printf("%.6lf", mid); return;
	}

	return;
}



int main()
{
	//输入阶段
	
	scanf("%d", &n);
	scanf("%d", &k);
	int i = 0;
	for ( i = 0; i < n; i++)
	{
		//scanf("%f", &N[i]);
		cin >> N[i];
	}


	//二分法确定距离；
	double length = N[i - 1] - N[0];
	//cout << length;
	Divide(0,length);



	return 0;
}