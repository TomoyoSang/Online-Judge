#include <iostream>
#include <cstdio>

using namespace std;

//ע�⣺���ַ�ֳ��������ϸ�����Ӳ�����Ϊ���ֵķ�ֳ���ģ���

//������߳�
int L = 0;
//ģ��������
int plate[101][101] = { 0 };
//��һ�ֽ���ʱ�ķ�ֳ���
int _plate[101][101] = { 0 };
//�հ׸�����
int blank = 0;
//��ֳ����
int turns = 0;
//�жϸ�λ���Ƿ�Ϊ�ո�
int _judge(int i, int j)
{
	if (i >= 0 && i < L&&j >= 0 && j < L&&_plate[i][j] == 0 && plate[i][j] == 0)
	{
		plate[i][j] = 1;
		return 1;
	}
	else return 0;
}
//��ֳ
void _multiply()
{
	while (blank > 0)
	{
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j)
			{
				if (_plate[i][j] == 1)
				{
					blank -= _judge(i + 1, j);
					blank -= _judge(i, j + 1);
					blank -= _judge(i - 1, j);
					blank -= _judge(i, j - 1);
				}
			}
		}
		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < L; ++j) {
				_plate[i][j] = plate[i][j];
			}
		}

		turns++;
	}
	return;

}

int main()
{
	cin >> L;
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			cin >> plate[i][j];
			_plate[i][j] = plate[i][j];
			if (plate[i][j] == 0)
				blank++;
		}
	}
	_multiply();
	cout << turns;

	return 0;
}