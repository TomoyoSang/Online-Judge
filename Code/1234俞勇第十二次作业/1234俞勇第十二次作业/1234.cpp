#include <iostream>
#include <cstdio>

using namespace std;

class dis
{
private:
	int* parent;
	int cur_size = 0;
public:
	dis(int s)
	{
		cur_size = s;
		parent = new int[s + 1];
		for (int i = 0; i <= s; ++i)
		{
			parent[i] = -1;
		}
	}
	~dis()
	{
		delete[]parent;
	}
	void Union(int root1, int root2)
	{
		if (root1 == root2)return;
		if (parent[root1] > parent[root2])
		{
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
		else
		{
			parent[root1] += parent[root2];
			parent[root2] = root1;
		}

	}
	int Find(int x)
	{
		if (parent[x] < 0)return x;
		return parent[x] = Find(parent[x]);
	}
};
int n, m;
int a, b, p;
int N[100006][3] = { 0 };
long long sum = 0;
void Quicksort(int left, int right)
{
	if (left == right)return;
	if (left - right == 1)return;
	int key1 = N[left][0];
	int key2 = N[left][1];
	int key3 = N[left][2];
	int tmp1 = left;
	int tmp2 = right;
	while (left < right)
	{
		while (left < right&&N[right][2] >= key3)
		{
			right--;
		}
		if (left < right)
		{
			N[left][0] = N[right][0];
			N[left][1] = N[right][1];
			N[left][2] = N[right][2];
			left++;
		}

		while (left < right&&N[left][2] <= key3)
		{
			left++;
		}
		if (left < right)
		{
			N[right][0] = N[left][0];
			N[right][1] = N[left][1];
			N[right][2] = N[left][2];
			right--;
		}
	}
	N[left][2] = key3;
	N[left][1] = key2;
	N[left][0] = key1;
	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);
	return;
}
bool flag[10005] = { 0 };

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &N[i][0], &N[i][1], &N[i][2]);
	}
	Quicksort(0, m - 1);
	dis ds(n);

	for (int i = 0; i < m; ++i)
	{
		
		if (ds.Find(N[i][0]) == ds.Find(N[i][1])&& (ds.Find(N[i][0])!=-1|| ds.Find(N[i][1])!=-1))continue;
		else
		{
			
			flag[N[i][0]] = 1;
			
			flag[N[i][1]] = 1;
			ds.Union(ds.Find(N[i][0]), ds.Find(N[i][1]));
			sum += N[i][2];
			

		}
	}

	printf("%lld", sum);
	return 0;
}