#include <iostream>
#include <cstdio>

using namespace std;

int n = 0;
int pre[100009] = { 0 };
int mid[100009] = { 0 };

struct node
{
	int elem = 0;
	node* left_son = NULL;
	node* right_son = NULL;

};
int _max(int a, int b)
{
	return (a > b) ? a : b;
}
void fix_root(int pre_l, int pre_r, int mid_l, int mid_r,node* root)
{
	int cur = 0;
	if (pre_l > pre_r)return;
	if (mid_l > mid_r)return;
	int element = pre[pre_l];
	for (int i = mid_l; i <= mid_r; ++i)
	{
		if (mid[i] == element)
		{
			cur = i;
			break;
		}
	}
	int left_len = cur - mid_l;
	int right_len = mid_r - cur;
	if (left_len != 0)
	{
		node* l_son = new node;
		root->left_son = l_son;
		fix_root(pre_l + 1, pre_l + left_len, mid_l, cur - 1, l_son);
	}
	if (right_len != 0)
	{
		node* r_son = new node;
		root->right_son = r_son;
		fix_root(pre_l + left_len + 1, pre_r, cur + 1, mid_r, r_son);
	}
	root->elem = element;
	return;
}
void post_print(node* p)
{
	if (p->left_son != NULL)post_print(p->left_son);
	if (p->right_son != NULL)post_print(p->right_son);
	printf("%d ", p->elem);
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &mid[i]);
	}
	node* root = new node;
	fix_root(0, n - 1, 0, n - 1, root);
	post_print(root);
	
	return 0;
}