#include <iostream>
#include <cstdio>
using namespace std;
//typedef long long ll
long long getm = 0, getn = 0;
long long calcu(long long m)
{
	//����λ��
	int cal = 1;
	long long cur = m;
	long long num = 0;//����
	int right = cur % 10;
	int left = 0;
	while (cur > 9)
	{
		cur /= 10;
		cal++;
	}
	left = cur;

	//һλ��
	if (cal == 1)return m;
	//��λ��
	else if (cal == 2)
	{
		cur = m;
		num = 9;
		for (int i = 1; i < left; i++)
		{
			num++;
		}
		if (right >= left)num++;
		return num;
	}
	//��+λ��
	else
	{
		num = 18;
		int j = 0;
		long long counter1 = 1, counter2 = 1;
		//calλ����ǰ���ܺ�
		for (int i = 3; i < cal; i++)
		{
			counter1 *= 9;
			j = i;
			while (j > 2)
			{
				counter1 *= 10;
				j--;
			}
			num += counter1;
			counter1 = 1;
		}
		//calλ����<left00000�����
		for (int i = 1; i < left; i++)
		{
			counter1 = 1;
			int j = cal - 2;
			while (j > 0)
			{
				counter1 *= 10;
				j--;
			}
			num += counter1;
		}
		//calλ����>=left00000�����
		cur = m;

		for (int k = 1; k < cal; k++)
		{
			counter2 *= 10;
		}
		cur -= counter2 * left;
		cur /= 10;
		num += cur;
		if (right >= left)num++;
		

		return num;
	}
	
}
int main()
{
	long long m, n;
	cin >> m >> n;
	getm = calcu(m);
	getn = calcu(n);
	
	
	long long cur = m;
	
	int right = cur % 10;
	int left = 0;
	while (cur > 9)
	{
		cur /= 10;
		
	}
	left = cur;
	if(left==right)
	cout << (getn - getm+1);
	else cout << (getn - getm);
	
	return 0;
}