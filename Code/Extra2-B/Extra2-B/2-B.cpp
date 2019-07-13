#include <iostream>
#include <cstdio>

using namespace std;

int N[1000009] = { 0 };
void  Quicksort(int left, int right)
{

	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	int key2 = N[left];


	while (left < right)
	{


		while (left < right  &&N[right] <= key2)
		{
			right--;
		}
		if (left < right)
		{
			N[left] = N[right];

			++left;
		}

		while (left < right &&N[left] >= key2)
		{
			left++;
		}
		if (left < right)
		{
			N[right] = N[left];

			--right;

		}


	}

	N[left] = key2;


	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);

	return;

}


int main()
{
	int bilibili = 0;
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &N[i]);
		}

		Quicksort(0, n - 1);
		for (int i = 0; i < m; i++)
		{
			if (i)printf(" ");
			printf("%d", N[i]);

		}
		printf("\n");
	}
	
	
	
	

	return 0;
}