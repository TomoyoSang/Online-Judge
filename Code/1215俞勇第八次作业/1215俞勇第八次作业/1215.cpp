#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int bernoulli[40009] = { 0 };
int cur_size = 0;
char order[9] = { 0 };
void insert()
{
	int k;
	scanf("%d", &k);
	int hole = ++cur_size;
	for (; hole > 1 && k < bernoulli[hole / 2]; hole /= 2)
		bernoulli[hole] = bernoulli[hole / 2];
		bernoulli[hole] = k;

		//for (int i = 0; i <= cur_size; i++)cout << bernoulli[i] << " ";
	    
		return;
}

void idelete()
{
	if (cur_size == 1)
	{
		bernoulli[1] = 0;
		cur_size--;
		return;
	}
	bernoulli[1] = bernoulli[cur_size];
	cur_size--;

	int child = 1;
	int hole = 1;
	int tmp = bernoulli[hole];
	for (; hole * 2 <= cur_size; hole = child)
	{
		child = hole * 2;
		if (child != cur_size && bernoulli[child + 1] < bernoulli[child])child++;
		if (bernoulli[child] < tmp)bernoulli[hole] = bernoulli[child];
		else break;

	}
	bernoulli[hole] = tmp;
	//for (int i = 0; i <= cur_size; i++)cout << bernoulli[i] << " ";
	return;
}

void mini()
{
	printf("%d\n", bernoulli[1]);
	return;
}
int main()
{
	int M;
	scanf("%d", &M);
	int counter = 0;
	for (; M > 0; M--)
	{
		memset(order, 0, sizeof(order));
		scanf("%s", order);
		if (strcmp(order, "insert") == 0)insert();
		else if (strcmp(order, "delete") == 0)idelete();
		else if (strcmp(order, "min") == 0)
		{
			/*if (!counter)counter++;
			else printf("\n");*/
			mini();
		}
	}

	return 0;
}