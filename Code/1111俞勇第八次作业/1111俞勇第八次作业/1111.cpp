#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char pre[30] = { 0 };
char mid[30] = { 0 };
char pos[2600] = { 0 };

int len = 0;

int max_size = 0;

int _max(int a, int b)
{
	return (a > b) ? a : b;
}
void fix_root(int pre_l, int pre_r, int mid_l, int mid_r, int gen)
{
	
	if (pre_l > pre_r)return;
	if (mid_l > mid_r)return;
	//if(pre_l==pre_r&&mid_l==mid_r)
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

void post_print()
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