#include <iostream>
#include <cstdio>

//»ØËÝ·¨
using namespace std;

int n, m, st, M;
struct node
{
	int num = 0;
	node* next = NULL;
};
node* nodelist[16];
int vis[16] = { 0 };
int cur_len = 0;
long long _path = 0;

void ifind(int pos)
{
	if (cur_len==M)
	{
		_path++;
		return;
	}

	
	if (cur_len < M)
	{
		node* p = nodelist[pos];
		while (p->next != NULL )
		{
			if (vis[p->next->num] != 0)
			{
				p = p->next;
				continue;
			}
			int cur = p->next->num;
			vis[cur] = 1;
			cur_len++;
			ifind(cur);
			vis[cur] = 0;
			cur_len--;
			p = p->next;
		}
	}
	
	
	return;
}
int main()
{
	
	cin >> n >> m >> st >> M;
	int a, b;
	for (int i = 0; i < 16; ++i)
	{
		nodelist[i] = new node;
	}

	for (int i = 0; i < m; ++i)
	{
	
		cin >> a >> b;
		node* q = new node;
		q->num = b;
		q->next = nodelist[a]->next;
		nodelist[a]->next = q;
	}

	
	vis[st] = 1;
	ifind(st);
	printf("%lld", _path);
	return 0;
}