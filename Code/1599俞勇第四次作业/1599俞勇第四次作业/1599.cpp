#include <iostream>
#include <cstdio>

using namespace std;

char stack1[100000] = { 0 };
char stack2[100000] = { 0 };
bool tree[1000000] = { 0 };
int iend1 = 0;
int iend2 = 0;
void push(char s)
{	
	stack1[iend1] = s;
	iend1++;
	if (iend2 > 0 && (s == ')'&&stack2[iend2 - 1] == '(') || (s == ']'&&stack2[iend2 - 1] == '[') || (s == '}'&&stack2[iend2 - 1] == '{'))
	{
		iend2--;

		tree[iend1 - 1] = true;
	}
	else
	{
		stack2[iend2] = s;
		iend2++;
	}
	return;
}
void pop()
{
	//·µ»Ø
	char s = 0;
	if (iend1 == 0)return;
	else 
	{

		s = stack1[iend1 - 1];
		//cout << s << endl;
		iend1--;

		if (tree[iend1] == 1)
		{
			if (s == ')')
			{
				stack2[iend2] = '(';
				iend2++;
			}
			else if (s == ']')
			{
				stack2[iend2] = '['; iend2++;
			}
			else if (s == '}')
			{
				stack2[iend2] = '{';
				iend2++;
			}
			//else iend2--;

			tree[iend1] = false;
		}
		else {
			iend2--;
		}
		
	}
	return;
}
char front()
{
	if (iend1 == 0)return '0';
	return stack1[iend1 - 1];
}
bool right()
{
	if (iend2 != 0)return 0;
	else return 1;
}


int main()
{
	int n;
	scanf("%d", &n);
	int x;
	char s = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		char q = 0;
		bool flag = 1;
		switch (x)
		{
		case 1:
			/*
			scanf("%c", &s); while (s != '('&&s != ')'&&s != '['&&s != ']'&&s != '{'&&s != '}')
		{
			scanf("%c", &s);
		}*/
			scanf(" %c", &s);
				push(s); break;
		case 2: pop(); break;
		case 3: q = front(); if (q != '0')printf("%c\n", q); break;
		case 4: flag = right(); 
			if (!flag)printf("No\n");
				else printf("Yes\n"); break;
		}
	}
	
	return 0;

}