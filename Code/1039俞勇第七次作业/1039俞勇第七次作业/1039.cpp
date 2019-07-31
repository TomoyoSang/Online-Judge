#include <iostream>
#include <cstdio>
using namespace std;


int N[66000][3] = { 0 };
int tree_pos[33000] = { 0 };

int counter = 0;
void print_node(int num)//后序遍历
{

	if (N[num][0] == 0)return;

	print_node(2 * num);
	print_node(2 * num + 1);
	if (!counter)counter++;
	else  printf(" ");
	printf("%d", N[num][0]);


	return;
}
int main()
{
	int n;
	scanf("%d", &n);
	int k = 0, left = 0, right = 0;
	int cur = 0;
	tree_pos[1] = { 1 };
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &k, &left, &right);
		cur = tree_pos[k];
		N[cur][0] = k;//节点的序号
		N[cur][1] = left;//左儿子
		N[cur][2] = right;//右儿子

		if (left != -1)
			tree_pos[left] = cur * 2;
		if (right != -1)
			tree_pos[right] = cur * 2 + 1;

	}
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!s)s++;
		else printf(" ");
		printf("%d", tree_pos[i]);

	}
	printf("\n");


	print_node(1);

	return 0;
}

