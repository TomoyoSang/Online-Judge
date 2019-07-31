#include <iostream>
#include <cstdio>

using namespace std;
//��ǰ׺�͡��㷨

int painter[1300][1300] = { 0 };
int maximum = 0;
int N, M;

int main()
{
	scanf("%d%d", &N, &M);
	char s = 0;
	int avai = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j =1; j <= M; j++)
		{
			
			s = cin.get();
			while (s != '-'&&s != 'X')
			{
				s = cin.get();
			}
			if (s == '-')avai = 0;
			else if (s == 'X')avai = 1;

			//�ӣ�0��0������i��j���ľ����ڵĺ�
			painter[i][j] = painter[i][j - 1] + painter[i - 1][j] - painter[i - 1][j - 1] + avai;
			
		}
	}
	
	
	int cur_max = 0;//��ǰ�����ο��
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = cur_max*2; j <= M; j++)
		{
			
			if (j == 0)
				continue;
			int counter = cur_max;
			for (; j >= counter * 2 && i >= counter; ++counter) {//�ӣ�i��j����ʼ��0��0������Ŀ�cur_max��С����
				if (painter[i][j] - painter[i][j - 2 * counter] - painter[i - counter][j] 
					+ painter[i - counter][j - 2 * counter] > 0)//==0ʱ���ʾ���С�������ǿհ׵�
					break;
			}
			--counter;
			if (counter > cur_max)cur_max = counter;
		}
	}


	cout << cur_max * cur_max * 2;

	return 0;
}
