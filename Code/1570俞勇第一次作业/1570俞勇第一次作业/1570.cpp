#include <iostream>
#include<cstdio>
using namespace std;

int compare(int likenum, int* comnum, int left, int right);


int main()
{
	//输入
	int common = 0, like = 0, i = 0, j = 0;
	//cin >> common >> like;
	scanf("%d%d", &common, &like);

	int *comnum, *likenum;
	comnum = new int[common];
	likenum = new int[like];

	for (i = 0; i < common; i++)
	{
		cin >> comnum[i];
	}
	for (i = 0; i < like; i++)
	{
		cin >> likenum[i];
	}

	i = 0;

	//分治法比较
	int big = 0;
	for (i = 0; i < like; i++)
	{
		big = common - 1 - compare(likenum[i], comnum, 0, common - 1);
		printf("%d\n", big);

	}


	return 0;



}


int compare(int likenum, int *comnum, int left, int right)
{
	int place = 0;
	if (left == right - 1) {
		if ((likenum > comnum[right]) || (likenum == comnum[right]))return right;
		else if (likenum < comnum[left])return left - 1;
		else return left;
	}

	int mid = (left + right) / 2;
	if ((likenum > comnum[mid]) || (likenum == comnum[mid]))
		place = compare(likenum, comnum, mid, right);

	else if (likenum < comnum[mid])
		place = compare(likenum, comnum, left, mid);

	return place;

}