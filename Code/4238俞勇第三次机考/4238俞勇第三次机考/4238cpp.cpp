#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int ope;
int X, Y;
int A, B;
int hidelist[200003] = { 0 };
class dis
{
private:
	int size;
	int * parent;
public:
	dis(int s)
	{
		size = s;
		parent = new int[s];
		for (int i = 0; i < s; ++i)
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
		return;
	}
	int Find(int x)
	{
		if (parent[x] < 0)return x;
		return parent[x] = Find(parent[x]);
	}

};

int main()
{
	scanf("%d %d", &n, &m);
	dis ds(n + 1);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &ope);
		if (ope == 1)
		{
			scanf("%d %d", &X, &Y);
			ds.Union(ds.Find(X), ds.Find(Y));
		}
		else if (ope == 2)
		{
			scanf("%d %d", &A, &B);
			if (hidelist[A] != -1 && hidelist[B] != -1)
			{
				if (ds.Find(A) == ds.Find(B))
				{
					printf("YES\n");

				}
				else printf("NO\n");

			}
			else
			{
				printf("NO");
				printf("\n");
			}

		}
		else if (ope == 3)
		{
			scanf("%d", &A);
			hidelist[A] = -1;
		}
	}

	return 0;

}