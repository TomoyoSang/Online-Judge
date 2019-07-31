#include <iostream>
#include <cstdio>

using namespace std;

//似乎可以用链表来做，类似于动态内存管理
//我的做法：
//先将若干个范围区间按照起始位置从小到大排序
//之后，按照任意一个区间i与后面区间j的关系分类处理：
//1.L1<=L2<=R1<=R2:		L2=L1,i++;(将前一个区间延长到后面，继续)
//2.L1<R1<=L2<R2:		sum+=R1-L1;i++;（由于出现了空白区间，将前一个区间加上再丢弃，从后面继续）
//3.L1<L2<R2<R1:		j++（被包含，继续）
//最后注意区间端点+1-1问题
int N[10000][2] = { 0 };
int n;

void Quicksort(int left, int right)
{
	if (left == right)return;
	else if (left - right == 1)return;
	else
	{
		int key = N[left][0];
		int key1 = N[left][1];
		int tmp1 = left;
		int tmp2 = right;

		while (left < right)
		{
			while (left < right&&N[right][0] >= key)
			{
				right--;
			}
			if (left < right)
			{
				N[left][0] = N[right][0];
				N[left][1] = N[right][1];
				left++;
			}
			while (left < right&&N[left][0] <= key)
			{
				left++;
			}
			if (left < right)
			{
				N[right][0] = N[left][0];
				N[right][1] = N[left][1];
				right--;
			}


		}
		N[left][0] = key;
		N[left][1] = key1;
		Quicksort(tmp1, left);
		Quicksort(left + 1, tmp2);


		return;
	}
}
int main()
{
	int counter = 0;
	int cur_num = 0;
	scanf("%d", &cur_num);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &N[i][0], &N[i][1]);
	}

	Quicksort(0, n - 1);

	int i = 0, j = 0;
	long long sum = 0;

	for (i = 0; i < n; i++)
	{

		for (j = i; j < n; j++)
		{

			if (N[i][1] >= N[j][1])
			{
				continue;

			}
			else if (N[i][1] < N[j][1])
			{
				if (N[i][1] >= N[j][0])
				{
					N[j][0] = N[i][0];
					i = j - 1;

					break;
				}
				else if (N[i][1] < N[j][0])
				{
					sum += N[i][1] - N[i][0] + 1;
					i = j - 1;

					break;

				}
			}

		}

		if (j == n)
		{
			sum += N[i][1] - N[i][0] + 1;
			break;
		}

	}

	cout << cur_num + 1 - sum;
	return 0;
}