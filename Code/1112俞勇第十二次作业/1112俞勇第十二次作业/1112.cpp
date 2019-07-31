#include <iostream>
#include <cstdio>

using namespace std;
//优先队列

int N[1006] = { 0 };//学术水平
bool flag[1006] = { 0 };//有没有问过
int pic[1003][1003] = { 0 };//朋友关系
int pri_que[100000] = { 0 };//优先队列:存的是序号不是学术水平
int cur_len = 0;//队列长度
void insert(int num)
{
	flag[num] = 1;
	pri_que[++cur_len] = num;
	int i = cur_len;
	while (i > 1 && N[pri_que[i / 2]] < N[num])
	{
		pri_que[i] = pri_que[i / 2];
		i /= 2;
	}
	
	pri_que[i] = num;
	return;
}
void down()
{
	int i = 1;
	int child = 1;
	int tmp = pri_que[i];
	for (; i * 2 <= cur_len; i=child)
	{
		child = i * 2;
		if (child!=cur_len&&N[pri_que[child]] < N[pri_que[child + 1]])
		{
			child++;
		}
		if (N[pri_que[child]] > N[tmp])pri_que[i] = pri_que[child];
		else break;
	}
	pri_que[i] = tmp;
	return;
}
void pop()
{
	if (cur_len == 1)
	{
		cur_len = 0;
		return;
	}
	
	int num = pri_que[cur_len--];
	pri_que[1] = num;
	down();
	return;
}
int front()
{
	if (cur_len > 0)return pri_que[1];
	
}
int main()
{

	int n, k;
	scanf("%d %d", &n, &k);
	//输入几个人的学术水平
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &N[i]);
	}
	//输入前面的几个人，并按照学术水平优先排序
	long long cur = 0;
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d", &cur);
		insert(cur);
		flag[cur] = 1;
	}

	//朋友关系
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &pic[i][j]);
		}
	}

	while (cur_len != 0)
	{
		cur = front();
		pop();
		for (int i = 1; i <= n; ++i)
		{
			if (pic[cur][i] == 1 && flag[i] != 1)
			{
				insert(i);
			}

		}
		printf("%d\n", cur);
	}
	
	return 0;
}