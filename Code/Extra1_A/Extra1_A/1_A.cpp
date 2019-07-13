#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char shop[10009][36]= { 0 };
char inc_shop[10009][36] = { 0 };
int inc_pri[10009] = { 0 };
int prices[10009] = { 0 };

void Quicksort2(int left, int right)
{
	if (left - right == 1)return;
	else if (left == right)return;

	int tmp1 = left;
	int tmp2 = right;
	char* key = new char[32];
	int key2 = inc_pri[left];
	strcpy(key, inc_shop[left]);
	while (left < right)
	{
		while (left < right&&strcmp(inc_shop[right], key) >= 0)
		{
			right--;
		}
		if (left < right)
		{
			strcpy(inc_shop[left], inc_shop[right]);
			inc_pri[left] = inc_pri[right];
			left++;
		}
		while (left < right&&strcmp(inc_shop[left], key) <= 0)
		{
			left++;
		}
		if (left < right)
		{
			strcpy(inc_shop[right], inc_shop[left]);
			inc_pri[right] = inc_pri[left];
			right--;
		}
	}
	
	strcpy(inc_shop[left], key);
	inc_pri[left] = key2;
	delete key;
	Quicksort2(tmp1, left);
	Quicksort2(left + 1, tmp2);
	return;
}
void Quicksort1(int left, int right)
{
	if (left - right == 1)return;
	else if (left == right)return;

	int tmp1 = left;
	int tmp2 = right;
	char* key = new char[32];
	int key2 = prices[left];
	strcpy(key, shop[left]);
	while (left < right)
	{
		while (left < right&&strcmp(shop[right], key) >= 0)
		{
			right--;
		}
		if (left < right)
		{
			strcpy(shop[left], shop[right]);
			prices[left] = prices[right];
			left++;
		}
		while (left < right&&strcmp(shop[left], key) <= 0)
		{
			left++;
		}
		if (left < right)
		{
			strcpy(shop[right], shop[left]);
			prices[right] = prices[left];
			right--;
		}
	}
	strcpy(shop[left], key);
	prices[left] = key2;
	delete key;
	Quicksort1(tmp1, left);
	Quicksort1(left + 1, tmp2);
	return;
}


int main()
{
	int bilibili = 0;
	int n;
	while (cin >> n) {

		memset(shop, 0, sizeof(shop));
		memset(prices, 0, sizeof(prices));
		memset(inc_pri, 0, sizeof(inc_pri));
		memset(inc_shop, 0, sizeof(inc_shop));
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &shop[i]);
		}
		Quicksort1(0, n - 1);

		int m = 0;
		scanf("%d", &m);
		int pla = 0;
		for (int i = 0; i < n; i++)
		{
			if (strcmp("memory", shop[i]) == 0)
			{
				pla = i;
				break;
			}
		}
		int irank = 1, cur = 0;
		for (; m > 0; m--)
		{
			memset(inc_pri, 0, sizeof(inc_pri));
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &inc_pri[i]);
				scanf("%s", &inc_shop[i]);
			}
			Quicksort2(0, n - 1);
			for (int i = 0; i < n; i++)
			{
				prices[i] += inc_pri[i];
			}

			cur = prices[pla];
			for (int i = 0; i < n; i++)
			{
				if (prices[i] > cur)irank++;
			}
			printf("%d\n", irank);
			irank = 1;
		}
	}
	
	return 0;
}