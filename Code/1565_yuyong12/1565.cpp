#include <iostream>
#include <cstdio>


using namespace std;

struct node
{
	node* next = NULL;
	int len = 0;
	int cur_num = 0;
};
node* nodelist[1000006];
int _path[1000030] = { 0 };
int n, m;

int ifront = 0;
int cur_len = 0;
int _size = 1000000;
int spfa[2000000] = { 0 };
int main()
{
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i <= n; ++i)
	{
		nodelist[i] = new node;
		nodelist[i]->cur_num = i;

	}
	int a, b, c;

	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		

		{
			node* p = new node;
			p->cur_num = b;
			p->len = c;

			p->next = nodelist[a]->next;
			nodelist[a]->next = p;

			node* q = new node;
			q->cur_num = a;
			q->len = c;

			q->next = nodelist[b]->next;
			nodelist[b]->next = q;


		}
		
	}

	
	for (int i = 2; i <= n; ++i)
	{
		_path[i] = 9999999;
	}

	spfa[ifront] = 1;
	cur_len = 1;
	int cur = 0;
	node* p;
	while (cur_len)
	{
		p = nodelist[spfa[ifront]];
		while (p->next != NULL)
		{
			cur = p->next->cur_num;
			if (_path[spfa[ifront]] + p->next->len < _path[cur])
			{
				spfa[(ifront + cur_len) % _size] = cur;
				_path[cur] = _path[spfa[ifront]] + p->next->len;
				cur_len++;
			}
			p = p->next;

		}
		cur_len--;
		ifront = (ifront + 1) % _size;
	}

	printf("%d", _path[n]);

	return 0;
}