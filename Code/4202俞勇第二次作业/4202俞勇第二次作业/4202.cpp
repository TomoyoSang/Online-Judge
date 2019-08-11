#include <iostream>
#include <cstring>
using namespace std;

int zhishu[100000][2][3] = { 0 };
int Value[100000][3] = { 0 };
int n;
int Gaoai = -1, Height = -1;


int Max(int a, int b)
{
	return (a > b) ? a : b;
}

int planttree(int i, int gaoai, int height)
{
	if (zhishu[i][gaoai][height] > 0)return zhishu[i][gaoai][height];


	if (i == 0)
	{
		Gaoai = gaoai;
		Height = height;

	}


	if (i == n - 1)
	{
		if (gaoai == 0 && height == 0)
		{
			//if (Gaoai == 0)return -1;
			//else
			return Value[n - 1][0];

		}

		else if (gaoai == 0 && height == 1)
		{
			if (Height == 1)return 0;
			else return Value[n - 1][1];

		}

		else if (gaoai == 1 && height == 1)
		{
			if (Height == 1)return 0;
			else return Value[n - 1][1];
		}

		else if (gaoai == 1 && height == 2)
		{
			//if (Height == 2)return -1;
			return Value[n - 1][2];
		}
		Gaoai = -1;
		Height = -1;
	}



	else
	{
		if (gaoai == 0 && height == 0)
		{
			zhishu[i][gaoai][height] = Max(planttree(i + 1, 1, 1), planttree(i + 1, 1, 2)) + Value[i][height];

		}

		else if (gaoai == 0 && height == 1)
		{
			zhishu[i][gaoai][height] = planttree(i + 1, 1, 2) + Value[i][height];

		}

		else if (gaoai == 1 && height == 1)
		{
			zhishu[i][gaoai][height] = planttree(i + 1, 0, 0) + Value[i][height];

		}

		else if (gaoai == 1 && height == 2)
		{
			zhishu[i][gaoai][height] = Max(planttree(i + 1, 0, 1), planttree(i + 1, 0, 0)) + Value[i][height];
		}


		return zhishu[i][gaoai][height];

	}
}


int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> Value[i][j];
		}

	}


	memset(zhishu, 0, sizeof(zhishu));

	int sum0 = planttree(0, 0, 0);
	memset(zhishu, 0, sizeof(zhishu));
	int sum1 = planttree(0, 0, 1);
	memset(zhishu, 0, sizeof(zhishu));
	int sum2 = planttree(0, 1, 2);
	memset(zhishu, 0, sizeof(zhishu));
	int sum3 = planttree(0, 1, 1);
	sum1 = (sum1 > sum0) ? sum1 : sum0;
	sum2 = (sum2 > sum3) ? sum2 : sum3;
	sum1 = (sum1 > sum2) ? sum1 : sum2;
	cout << sum1;
	
	return 0;
}