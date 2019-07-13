#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	node* next = NULL;
	int node_num = 0;
	int dep = 0;

};

node* nodelist[30009];
bool vis[30009] = { 0 };

int dep_dep[30009] = { 0 };
void insert(int a, int b)
{
	node* p = new node;
	p->node_num = b;
	p->next = nodelist[a]->next;
	nodelist[a]->next = p;

	p = new node;
	p->node_num = a;
	p->next = nodelist[b]->next;
	nodelist[b]->next = p;

	return;
}

int find_dep(int _pos)
{
	vis[_pos] = 1;
	
	int cur = 0;
	int max1 = 0, max2 = 0;
	node* p = nodelist[_pos];
	while (p->next != NULL)
	{
		if (!vis[p->next->node_num])
		{
			vis[p->next->node_num] = 1;
			cur = find_dep(p->next->node_num) + 1;
			if (max1 < max2)
			{
				if (cur > max1)max1 = cur;
			}
			else
			{
				if (cur > max2)max2 = cur;
			}
		}
		
		p = p->next;
	}


	if (max1 == 0 || max2 == 0)dep_dep[_pos] = (max1 > max2) ? max1 : max2;
	else dep_dep[_pos] = max1 + max2;
	nodelist[_pos]->dep = (max1 > max2) ? max1 : max2;
	
	return nodelist[_pos]->dep;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> n >> m;
	for (int i = 0; i <= m + n; ++i)
	{
		nodelist[i] = new node;
		nodelist[i]->node_num = i;
	}
	int cur;
	for (int i = 2; i <= n; ++i)
	{
		cin >> cur;
		insert(i, cur);
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> cur;
		insert(i + n, cur);
	}

	

	int _dep = find_dep(1);
	int _depdep = 0;
	for (int i = 1; i <= n + m; ++i)
	{
		_depdep = (dep_dep[i] > _depdep) ? dep_dep[i] : _depdep;
	}

	cout << _depdep;

	return 0;
}