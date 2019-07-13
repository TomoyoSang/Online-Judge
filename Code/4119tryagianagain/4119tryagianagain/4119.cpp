#include <iostream>
#include <cstdio>

using namespace std;

int n, A, B, C;
int par[20007] = { 0 };

int _par = 0;
struct node
{
	int num;
	int len;
	node* next = NULL;
};
node* nodelist[20002];

class dis
{
public:
	int* parent;
	int _size;

	dis(int n)
	{
		parent = new int[n + 1];
		_size = n;
		for (int i = 0; i <= n; ++i)
		{
			parent[i] = -1;
		}
	}
	~dis() {  };

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
void insert(int a, int b, int c)
{
	node*p = nodelist[a];
	node* q = new node;
	q->num = b; q->len = c;
	q->next = p->next;
	p->next = q;
	
	p = nodelist[b];
	node* r = new node;
	r->num = a;
	r->len = c;
	r->next = p->next;
	p->next = r;
	return;
}
void buildtree(int root)
{
	node* p = nodelist[root];
	int parent = par[root];
	while (p->next != NULL)
	{
		if (p->next->num != parent)
		{
			par[p->next->num] = root;
			buildtree(p->next->num);
		}
		p = p->next;
	}
	return;
}
bool flag = 0;
void Findpar(dis ds, int cur)
{
	node* p = nodelist[cur];
	while (p->next != NULL)
	{
		
		if (p->next->num != par[nodelist[cur]->num])
		{
			Findpar(ds, p->next->num);
			if (flag)return;
			ds.Union(ds.Find(cur), ds.Find(p->next->num));
			if (ds.Find(B) == ds.Find(C) && ds.Find(B) != -1 && _par == 0)
			{
				_par = cur;
				flag = 1;
				return;

			}
		}
		

		p = p->next;
		
	}

	return;
}

int main()
{

	scanf("%d %d %d %d", &n, &A, &B, &C);
	int a, b, c;
	for (int i = 1; i <= n; ++i)
	{
		nodelist[i] = new node;
		nodelist[i]->num = i;
		nodelist[i]->len = 0;
	}
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		insert(a, b, c);
	}
	
	/*node* s = nodelist[1];
	for (int i = 1; i <= n; ++i)
	{
		s = nodelist[i];
		while (s->next != NULL)
		{
			printf("%d ", s->next->num);
			s = s->next;
		}
		
		printf("\n");
	
	}*/
	
	int cur = A;
	buildtree(A);
	

	dis ds(n);

	Findpar(ds, A);

	long long sum = 0;
	cur = 0;
	node* p = nodelist[B];
	while (p->num != _par)
	{
		cur = par[p->num];
		while (p->next->num != cur)p = p->next;
		sum += p->next->len;
		p = nodelist[par[B]];
	}
	
	p = nodelist[C];
	while (p->num != _par)
	{
		cur = par[p->num];
		while (p->next->num != cur)p = p->next;
		sum += p->next->len;
		p = nodelist[cur];
	}
	
	p = nodelist[_par];
	while (p->num != A)
	{
		cur = par[p->num];
		while (p->next->num != cur)p = p->next;
		sum += p->next->len;
		p = nodelist[cur];
	}

	printf("%d\n", _par);
	printf("%lld", sum);
	return 0;
}