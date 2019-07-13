#include <iostream>
#include <cstdio>
//#include <cstdlib>

using namespace std;
int n, m;
int N[200009][3] = { 0 };
class dis
{
public:
	int _size = 0;
	int* parent;
	dis(int n)
	{
		_size = n + 1;
		parent = new int[n + 1];
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = -1;
		}
	}

	~dis() { delete[]parent; }

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
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}

		return;
	}
};

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
	Quicksort(0, m - 1);

	dis ds(n);
	long long counter = 0;
	long long sum = 0;
	for (int i = 0; counter <= n - 1 && i < m; ++i)
	{
		if (ds.Find(N[i][1]) != ds.Find(N[i][2])|| (ds.Find(N[i][1]) == ds.Find(N[i][2])&&ds.Find(N[i][1])==-1))
		{
			sum += N[i][0];
			ds.Union(ds.Find(N[i][1]), ds.Find(N[i][2]));
			counter++;
		}

	}

	if (counter == n - 1)cout << sum;
	else cout << "orz";

	//system("pause");
	return 0;
}