#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
	node* next = NULL;
	int cur_num = 0;
	long long expense = 0;
	long long cur_len = 0;
};
node* nodelist[1006];

void insert(int a, int b, long long c,long long d)
{
	node* p = new node;
	p->cur_num = b;
	p->cur_len = c;
	p->expense = d;

	p->next = nodelist[a]->next;
	nodelist[a]->next = p;

	node* q = new node;
	q->cur_num = a;
	q->cur_len = c;
	q->expense = d;

	q->next = nodelist[b]->next;
	nodelist[b]->next = q;
	return;
}
long long _path[1006] = { 0 };
long long _exp[1006] = { 0 };

int spfa[1000000] = { 0 };
int ifront = 0;
int cur_len = 0;
int _size = 1000000;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;
	
	for (int i = 0; i <= 1000; ++i)
	{
		nodelist[i] = new node;
		nodelist[i]->cur_num = i;
		_path[i] = 999999999;
		_exp[i] = 99999999;
	}
	

	int a, b;
	long long c, d;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		cin >> c >> d;
		insert(a, b, c, d);
	}
	int s, t;
	cin >> s >> t;

	_path[s] = 0;
	_exp[s] = 0;

	spfa[ifront] = s;
	cur_len = 1;
	int cur = 0;
	while (cur_len != 0)
	{
		node* p = nodelist[spfa[ifront]];
		while (p->next != NULL)
		{
			cur = p->next->cur_num;
			if (_path[spfa[ifront]] + p->next->cur_len < _path[cur]|| 
				(_path[spfa[ifront]] + p->next->cur_len == _path[cur])&&_exp[spfa[ifront]]+p->next->expense<_exp[cur])
			{
				spfa[(ifront + cur_len) % _size] = cur;
				_path[cur] = _path[spfa[ifront]] + p->next->cur_len;
				_exp[cur] = _exp[spfa[ifront]] + p->next->expense;
				cur_len++;
			}
			p = p->next;

		}
		cur_len--;
		ifront = (ifront + 1) % _size;
	}

	cout << _path[t] << " " << _exp[t];
	return 0;
}