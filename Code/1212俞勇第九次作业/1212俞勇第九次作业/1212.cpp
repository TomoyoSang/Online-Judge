#include <iostream>
#include <cstdio>

//½¨Ê÷+BFS
using namespace std;

struct node
{
	int l_son = 0;
	int r_son = 0;
	int weight = 0;
	int node_num = 0;
	

};

node* cur[100003] = { NULL };
//BFS
int node_que[100003] = { 0 };
int ifront = 0;
int cur_len = 0;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		if (cur[i] == NULL)
		{
			cur[i] = new node;
		}
		scanf("%d %d %d", &cur[i]->l_son, &cur[i]->r_son, &cur[i]->weight);
		
		if (cur[i]->l_son != 0)
		{
			if(cur[cur[i]->l_son]== NULL)
			cur[cur[i]->l_son] = new node;
			cur[cur[i]->l_son]->node_num = i;
		}
		if (cur[i]->r_son != 0)
		{
			if (cur[cur[i]->r_son] == NULL)
			cur[cur[i]->r_son] = new node;
			cur[cur[i]->r_son]->node_num = i;
		}

	}

	int pointer = 1;
	while (cur[pointer]->node_num!=0)
	{
		pointer = cur[pointer]->node_num;
	}
	//BFS
	
	node_que[ifront] = pointer;
	cur_len++;
	
	while (cur_len!=0)
	{
		printf("%d ", cur[node_que[ifront]]->weight);
		if (cur[node_que[ifront]]->l_son != 0)
		{
			
			node_que[ifront + cur_len] = cur[node_que[ifront]]->l_son;
			cur_len++;

		}
		if (cur[node_que[ifront]]->r_son != 0)
		{
			
			node_que[ifront + cur_len] = cur[node_que[ifront]]->r_son;
			cur_len++;
		}
		ifront++;
		cur_len--;
	}

	return 0;
	


}