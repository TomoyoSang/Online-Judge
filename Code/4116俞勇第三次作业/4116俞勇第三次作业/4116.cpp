#include <iostream>
#include <cstdio>

using namespace std;


int pos[100020] = { 0 };
int N, S;
void divide(int left, int right)
{
	if (right - left == 1)
	{
		int j = 0,m=1, k = S - 1;
		
		while (m < N)
		{
			if (pos[m] - pos[j] >= right)
			{
				k--;
				j = m ;
			}
			else m++;
			if (k == 0)break;
		}
		if (k == 0)printf("%d", right);
		else printf("%d", left);
		return;
	}
	int mid = (left + right) / 2;
	int j = 0, m = 1, k = S - 1;

	

	while (m < N)
	{
		if (pos[m] - pos[j] >= mid)
		{
			k--;
			j = m;
		}
		else m++;
		if (k == 0)break;
	}
	if (k > 0)divide(left, mid);
	else divide(mid, right);
	return;
}

void  Quicksort( int left, int right)
{

	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	int key2 = pos[left];
	

	while (left < right)
	{


		while (left < right  &&pos[right] >= key2)
		{
			right--;
		}
		if (left < right)
		{
			pos[left] = pos[right];
			
			++left;
		}

		while (left < right &&pos[left] <= key2)
		{
			left++;
		}
		if (left < right)
		{
			pos[right] = pos[left];
		
			--right;

		}


	}

	pos[left] = key2;
	


	Quicksort(tmp1, left);
	Quicksort( left + 1, tmp2);

	return;

}

int main()
{
	scanf("%d%d", &N, &S);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &pos[i]);
	}
	Quicksort(0, N - 1);
	divide(0,pos[N-1]-pos[0]);


	return 0;
}