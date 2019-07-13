#include<iostream>

using namespace std;

void righttime(int left, int right);
int calcutime(int mid);
int Condition[100000];
int TimeLimit = 0;
int Rode = 0;
int iftime[3];
int i = 0, j = 0;
int main()
{

	char s = 0;
	cin >> TimeLimit >> Rode >> iftime[0] >> iftime[1] >> iftime[2];

	for (i = 0; i < Rode; i++)
	{
		cin >> s;
		if (s == 'u')Condition[i] = 0;
		else if (s == 'f')Condition[i] = 1;
		else if (s == 'd')Condition[i] = 2;

	}

	i = 0;
	j = Rode - 1;
	righttime(i, j);
	return 0;
}

void righttime(int left, int right)
{
	if ((right - left) <= 1)
	{
		if (calcutime(right) > TimeLimit)
		{
			if (calcutime(left) > TimeLimit) { cout << left; return; }
			else { cout << left + 1; return; }
		}
		else { cout << right + 1; return; }

	}
	int mid = (left + right) / 2;
	int Time = calcutime(mid);
	if (Time > TimeLimit)
		righttime(left, mid);
	else if (Time == TimeLimit)
	{
		cout << mid + 1; return;
	}
	else righttime(mid, right);

}

int calcutime(int mid)
{
	//bool flag=1;
	int times = 0;
	for (i = 0; i <= mid; i++)
	{
		times += iftime[Condition[i]];
	}
	for (i = mid; i >= 0; i--)
	{
		times += iftime[2 - Condition[i]];
	}
	return times;

}
