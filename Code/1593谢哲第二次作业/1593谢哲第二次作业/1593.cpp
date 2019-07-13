#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N, R = 0;
int P[200005] = { 0 };
int S[200005] = { 0 };
int Num[200005] = { 0 };

bool bijiao(const int& a, const int& b) {
	return P[a] > P[b] || (P[a] == P[b] && a < b);
}

void Quicksort(int* istart, int* iend) {
	if (istart == iend)
		return;
	auto i = istart, j = iend;
	--j;
	if (i == j)
		return;
	//交换
	auto key = *istart;
	for (bool status = true; i != j;) {
		if (status) {
			if (bijiao(*j, key)) {
				*i = *j;
				++i;
				status = false;
			}
			else
				--j;
		}
		else {
			if (bijiao(key, *i)) {
				*j = *i;
				--j;
				status = true;
			}
			else
				++i;
		}
	}
	*i = key;
	//递归
	Quicksort(istart, ++i);
	Quicksort(i, iend);
}


void place(int pos) {
	auto tmp = Num[pos];
	auto s = pos - 1;
	for (; s >= 0; --s) {
		if (bijiao(tmp, Num[s])) {
			Num[s + 1] = Num[s];
		}
		else
			break;
	}
	Num[s + 1] = tmp;
}

int main()
{
	//输入
	scanf("%d%d", &N, &R);
	for (int i = 0; i < 2 * N; i++)
	{
		scanf("%d", &P[i]);
		Num[i] = i;
	}
	for (int i = 0; i < 2 * N; i++)
	{
		scanf("%d", &S[i]);
	}
	Quicksort(Num, Num + 2 * N);
	for (int i = 0; i < R; i++)
	{
		//先比赛，后排名

		for (int m = 0; m < 2 * N; m += 2) {
			if (S[Num[m]] > S[Num[m + 1]]) {
				P[Num[m]] += 2;
				place(m);
			}
			else if (S[Num[m]] == S[Num[m + 1]]) {
				++P[Num[m]];
				++P[Num[m + 1]];
				place(m);
				place(m + 1);
			}
			else {
				P[Num[m + 1]] += 2;
				place(m + 1);
			}
		}
	}

	//输出
	for (int i = 0; i < 2 * N; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", Num[i] + 1);

	}
	return 0;
}
