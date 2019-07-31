#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
//任意一个子树（序列的一个片段），前序的第一个为根，中序中根的左边为左子树，右边为右子树

char pre[30] = { 0 };//前序序列
char mid[30] = { 0 };//中序序列
char pos[2600] = { 0 };//树

int len = 0;

int max_size = 0;

int _max(int a, int b)
{
	return (a > b) ? a : b;
}
void fix_root(int pre_l, int pre_r, int mid_l, int mid_r, int gen)//闭区间
{
	
	if (pre_l > pre_r)return;
	if (mid_l > mid_r)return;
	char root = pre[pre_l];
	int cur = 0;
	for (int i = mid_l; i <= mid_r; i++)
	{
		if (mid[i] == root)cur = i;
	}
	int left_len = cur - mid_l;
	int right_len = mid_r - cur;
	if(left_len)
	fix_root(pre_l+1,pre_l+left_len,mid_l,cur-1,2 * gen);
	if(right_len)
	fix_root(pre_l + left_len + 1, pre_r, cur + 1, pre_r, 2 * gen + 1);
	pos[gen] = root;
	max_size = _max(max_size, gen);
	return;
}

void post_print()//输出后序
{
	for (int i = 1; i <= max_size; i++)
	{
		if (pos[i] >= 'A'&&pos[i] <= 'Z')printf("%c ", pos[i]);
		else printf("NULL ");
	}
	return;
}
int main()
{
	scanf("%s", pre);
	scanf("%s", mid);

    len = strlen(pre);
	fix_root(0, len-1, 0, len-1, 1);
	
	post_print();
	return 0;
}