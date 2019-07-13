#include <iostream>
#include <cstdio>

using namespace std;
int n, m;
int N[100005][3] = { 0 };
void  Quicksort(int left, int right)
{

	if (left == right)return;
	if (left - right == 1)return;

	int tmp1 = left;
	int tmp2 = right;

	int key2 = N[left][0];
	int key3 = N[left][1];
	int key4 = N[left][2];


	while (left < right)
	{


		while (left < right  &&N[right][0] >= key2)
		{
			right--;
		}
		if (left < right)
		{
			N[left][0] = N[right][0];
			N[left][1] = N[right][1];
			N[left][2] = N[right][2];
			++left;
		}

		while (left < right &&N[left][0] <= key2)
		{
			left++;
		}
		if (left < right)
		{
			N[right][0] = N[left][0];
			N[right][1] = N[left][1];
			N[right][2] = N[left][2];
			--right;

		}


	}

	N[left][0] = key2;
	N[left][1] = key3;
	N[left][2] = key4;

	Quicksort(tmp1, left);
	Quicksort(left + 1, tmp2);

	return;

}

class dis
{
public:
	int* parent;
	int _size = 0;

	dis(int n)
	{
		parent = new int[n + 1];
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = -1;
		}
		_size = n;
	}

	~dis() { delete[] parent; }

	int Find(int x)
	{
		if (parent[x] < 0)return x;
		return parent[x] = Find(parent[x]);
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
		return;
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> N[i][1] >> N[i][2] >> N[i][0];
	}

	dis ds(n);
	Quicksort(0, m - 1);
	int x1 = 0, x2 = 0;
	int counter = 0;
	for (int i = 0; i < m; ++i)
	{
		x1 = ds.Find(N[i][1]);
		x2 = ds.Find(N[i][2]);
		if (x1 != x2 || (x1 == x2 && x1 == -1))
		{
			ds.Union(x1, x2);
			++counter;
		}

		if (counter == n - 1)
		{
			cout << N[i][0];
			break;
		}
	}

	if (counter != n - 1)
		cout << -1;
	//system("pause");
	return 0;
}