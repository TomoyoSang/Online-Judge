#include <iostream>
#include <cstdio>

using namespace std;

int N[1003] = { 0 };
int n, m;
void avr(int l, int r)
{
	double cur = 0;
	for (int i = l; i <= r; ++i)
	{
		cur += N[i];
	}
	printf("%.2f\n", cur / (r - l + 1));
	return;
}

void _max(int l,int r)
{
	int cur_max = 0;
	for (int i = l; i <= r; ++i)
	{
		cur_max = (cur_max > N[i]) ? cur_max : N[i];
	}
	printf("%d\n", cur_max);
}
void roll_over(int l, int r)
{
	int len = r - l;
	int key = N[l];
	int cur_l = 0, cur_r = len;
	while (cur_l <cur_r)
	{
		key = N[l + cur_l];
		N[cur_l + l] = N[cur_r + l];
		N[cur_r + l] = key;
		cur_l++;
		cur_r--;
	}

	return;
}
void print(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		printf("%d ", N[i]);
	}
	printf("\n");
	return;
}
void down(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		if(N[i]!=0)
		N[i]--;
	}
	return;
}
int main()
{
	int cur_max = 0;
	scanf("%d %d", &n, &m);
	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &N[i]);
	}

	int ope = 0;
	int l = 0, r = 0;
	for (; m > 0; --m)
	{
		scanf("%d", &ope);
		scanf("%d %d", &l, &r);
		switch (ope)
		{
		case 0:
		{
			avr(l, r);
			break;
		}
		case 1:
		{
		
			_max(l, r);
			break;
		}
		case 2:
		{
			roll_over(l, r);
			break;
		}
		case 3:
		{
			print(l, r);
			break;
		}
		case 4:
		{
			down(l, r);
			break;
		}

		}

	}


	return 0;
}