#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int trains[1020] = { 0 };
int orders[1020] = { 0 };

int main() 
{
	int T = 0;
	scanf("%d", &T);
	int N, M;
	for (; T > 0; T--)
	{
		int j = 0, i = 0;
		memset(trains, 0, sizeof(trains));
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &orders[i]);//Ҫ���˳��
		}

		i = 0;
		int counter = 0;
		
		bool flag = 1;//�Ƿ��ܳɹ�����

		//���ȹ���
		//i--���л𳵵ĵ�i��
		//j--Ҫ���˳��ĵ�j�ڳ���
		while (j < N)
		{
			if (i == orders[j])//�ó����ڻ���
			{
				i++;
				j++;
			}
			else if (counter != 0)//����վ���г�
								//����վ������ĳ��Ƿ���������	
			{
				if (trains[counter - 1] == orders[j])
				{
					j++;
					counter--;
				}
				else if (trains[counter - 1] > orders[j])//��վ������ı�Ҫ��Ĵ��ˣ�˵���ýڳ���������������ˣ����Ȳ��ɹ�
				{
					printf("NO\n");
					flag = 0;
					break;
				}
				else if (trains[counter - 1] < orders[j])//��վ�������Ҫ���С�������û��Ϲ������ڳ��ᣬ���ܲ��ܰ�����ĳ����ڳ���
				{
					trains[counter] = i;
					counter++;
					i++;
				}
			
			}
			else //��վû���ˣ�ֱ�����￪
			{
				trains[counter] = i;
				counter++;
				i++;
			}
			
			if (i == N)//��ʱԭ���Ļ��Ѿ�ȫ��ȥ���߽���վ��
			{
				if (j == N)break;//����������
				else if (counter > 0 && trains[counter - 1] == orders[j])//�ѳ�վ��ĳ��ᶼ������
				{
					j++;
					counter--;
				}
				else
				{
					printf("NO\n");
					flag = 0;
				}
			}
				
			if (counter > M)//���أ����Ȳ��ɹ�
			{
				printf("NO\n");
				flag = 0;
				break;
			}
				
			
		}
		if (flag)printf("YES\n");

		
	}

	return 0;
}