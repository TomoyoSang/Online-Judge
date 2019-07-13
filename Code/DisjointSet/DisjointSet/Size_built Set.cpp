#include <iostream>
#include <cstdio>

using namespace std;

class DisjointSet
{
private:
	int size;
	int *parent;

public:
	DisjointSet(int s)
	{
		size = s;
		parent = new int[size];
		for (int i = 0; i < s; ++i)
		{
			parent[i] = -1;
		}

	}
	~DisjointSet()
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


int main()
{
	DisjointSet dis(6);
	dis.Union(4, 5);
	dis.Union(2, 3);
	int root3 = dis.Find(3);
	int root5 = dis.Find(5);
	printf("%d\n", root3);
	printf("%d\n", root5);
	dis.Union(2, 4);
	dis.Union(1, 2);
	int root1 = dis.Find(1);
	int root2 = dis.Find(2);
	printf("%d\n", root1);
	printf("%d\n", root2);

	return 0;




	return 0;
}