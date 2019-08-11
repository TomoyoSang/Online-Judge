#include <iostream>
#include <cstdio>
//#include <cstdlib>


using namespace std;
struct node
{
	node* next = NULL;
	int cur_num = 0;
	int cur_len = 0;
	int par = 0;
	int dep = 0;
};

node* nodelist[20005];

int N, A, B, C;
void insert(int a, int b, int c)
{
	node* p = new node;
	p->cur_num = b;
	p->cur_len = c;
	
	p->next = nodelist[a]->next;
	nodelist[a]->next = p;

    node* q = new node;
	q->cur_num = a;
	q->cur_len = c;

	q->next = nodelist[b]->next;
	nodelist[b]->next = q;
	return;
}
bool vis[20005] = { 0 };

void DFS(int cur_pos, int dep)
{
	nodelist[cur_pos]->dep = dep;
	vis[cur_pos] = 1;
	node* p = nodelist[cur_pos];
	while (p->next != NULL)
	{
		if (!vis[p->next->cur_num])
		{
			nodelist[p->next->cur_num]->par = cur_pos;
			nodelist[p->next->cur_num]->dep = dep + 1;
			DFS(p->next->cur_num, dep + 1);
		}
		p = p->next;
		
	}
	return;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A >> B >> C;
	for (int i = 1; i <=N; ++i)
	{
		nodelist[i] = new node;
	}
	int a, b, c;
	for (int i = 1; i < N; ++i)
	{
		cin >> a >> b >> c;
		insert(a, b, c);
	}


	nodelist[A]->dep = 0;
	vis[A] = 1;
	DFS(A, 0);
	
	long long sum = 0;
	while (nodelist[B]->dep != nodelist[C]->dep)
	{
		while (nodelist[C]->dep > nodelist[B]->dep)
		{
			node* p = nodelist[nodelist[C]->par];
			while (p->next->cur_num != C)
			{
				p = p->next;
			}
			sum += p->next->cur_len;
			C = nodelist[C]->par;
		}
		
		while (nodelist[B]->dep > nodelist[C]->dep)
		{
			node* p = nodelist[nodelist[B]->par];
			while (p->next->cur_num != B)
			{
				p = p->next;
			}
			sum += p->next->cur_len;
			B = nodelist[B]->par;
		}
	}

	while (B != C)
	{
		node* p = nodelist[nodelist[C]->par];
		while (p->next->cur_num != C)
		{
			p = p->next;
		}
		sum += p->next->cur_len;
		C = nodelist[C]->par;

		p = nodelist[nodelist[B]->par];
		while (p->next->cur_num != B)
		{
			p = p->next;
		}
		sum += p->next->cur_len;
		B = nodelist[B]->par;
	}

	while (nodelist[C]->dep != 0)
	{
		node* p = nodelist[nodelist[C]->par];
		while (p->next->cur_num != C)
		{
			p = p->next;
		}
		sum += p->next->cur_len;
		C = nodelist[C]->par;
	}
	cout << B << "\n";
	cout << sum ;
	//system("pause");
	return 0;
}