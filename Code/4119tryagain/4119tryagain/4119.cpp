#include <iostream>
#include <cstdio>

using namespace std;
int n, A, B, C;
long long sum = 0;
int pos = 0;

bool vis[20005] = { 0 };
struct node
{
	int num = 0;
	int len = 0;
	node* next = NULL;
};
node* nodelist[20005];
void insert(int a, int b, int c)
{
	node* p = nodelist[a];
	node*q = nodelist[b];

	node* r = new node;
	r->next = p->next;
	r->len = c;
	r->num = b;
	p->next = r;

	node* s = new node;
	s->next = q->next;
	s->num = a;
	s->len = c;
	q->next = s;

	return;
}



class dis
{
public:
	int parent[20002];
	int _size = 20002;

	dis()
	{
		for (int i = 0; i <= 20002; ++i)
		{
			parent[i] = -1;
		}
	}
	~dis() { };
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

int prev = 0;
int par = 0;
void post_order(int prev, int pos);
dis ds;
int main()
{
	scanf("%d %d %d %d", &n, &A, &B, &C);

	for (int i = 0; i <= n; ++i)
	{
		nodelist[i] = new node;
	}

	int a, b, c;

	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		insert(a, b, c);
	}
	vis[A] = 1;
	post_order(A, A);


	node* q = nodelist[B];
	int cur = B;

	while (1)
	{
		if (cur == par)break;
		while (q->next->num != ds.parent[cur])
		{
			q = q->next;
		}

		sum += q->next->len;
		cur = q->next->num;
		if (cur == par)break;
		q = nodelist[q->next->num];
	}

	node* r = nodelist[C];
	cur = C;

	while (1)
	{
		if (cur == par)break;
		while (r->next->num != ds.parent[cur])
		{
			r = r->next;
		}

		sum += r->next->len;
		cur = r->next->num;
		if (cur == par)break;
		r = nodelist[r->next->num];
	}

	node* k = nodelist[par];
	cur = par;

	while (1)
	{
		if (cur == A)break;
		while (k->next->num != ds.parent[cur])
		{
			k = k->next;
		}

		sum += k->next->len;
		cur = k->next->num;
		if (cur == A)break;
		k = nodelist[k->next->num];
	}

	printf("%d\n", par);
	printf("%lld", sum);

	return 0;
}

void post_order(int prev, int pos)
{
	node* p = nodelist[pos];
	vis[pos] = 1;
	while (p->next != NULL)
	{
		if (!vis[p->next->num])
		{
			post_order(pos, p->next->num);
			vis[p->next->num] = 1;
			if (ds.Find(B) == ds.Find(C) && par == 0)
			{
				par = ds.Find(B);
			}

		}
		p = p->next;
	}
	if (prev != A)
		ds.Union(ds.Find(prev), ds.Find(pos));
	return;

}