#include <iostream>
#include <cstdio>
using namespace std;

int queue[400009] = { 0 };
int target[400009] = { 0 };
int N, K;
int istart = 0, iend = 0;
int cur = 0;//���ֵ�ļ�¼
void insert(int i)
{
	
	int j = iend;
	for (; j > istart; j--)
	{
		if (target[j - 1] >= i)break;
	}
	target[j] = i;
	iend = j + 1;
	return;
}
void del(int i)
{
	if (target[istart] == i)istart++;
	return;
}
int main()
{
	//����
	scanf("%d%d", &N, &K);
	int i=0, j = 0;
	for ( i = 0; i < N; i++)
	{
		scanf("%d", &queue[i]);

	}

	for (j =0 ; j < K; j++)
	{
		queue[j+N] = queue[j];
		insert(queue[j]);
	}
	cur = target[istart];
	
	for (i = K; i < N + K; i++)
	{
		del(queue[i - K]);
		insert(queue[i]);
		
		
		cur = (target[istart] < cur) ? target[istart] : cur;
	}

	printf("%d", cur);

	return 0;
}
/*
#include "iostream"
#include "cstdio"
using namespace std;

int val[400009] = { 0 };
//����������
class f_queue {
public:
	//�洢�����������ݵ�����
	int queue_data[400009] = { 0 };
	//��ͷԪ��λ��
	int start = 0;
	//��βԪ��λ��
	int end = 0;
	//���뺯��
	void push(int num) {
		int i = end;
		//�Ӷ�β��ʼɨ�裬��С��num��Ԫ��ȫ��������ֱ���������ڵ���num��Ԫ��
		for (; i > start; --i) {
			if (queue_data[i - 1] >= num)
				break;
		}
		//��num���뵥��������
		queue_data[i] = num;
		end = i + 1;
	}
	//��������
	void pop(int num) {
		//�ж���Ҫ������num�Ƿ����ͷԪ����ȣ��������򽫶�ͷ���ӣ����������򲻽����κβ���
		if (num == queue_data[start])
			++start;
	}
	//���ض�ͷԪ��
	int front() {
		return queue_data[start];
	}
};

//��������
f_queue qdata;

int main() {
	int N, K;
	cin >> N >> K;

	int init = 0;
	for (int i = 0, cur_max = 0; i < N; ++i) {
		scanf("%d", &val[i]);
	}

	//ƴ�ӣ����ҽ�ǰK��Ԫ���뵥������
	for (int i = 0; i < K; ++i) {
		val[N + i] = val[i];
		qdata.push(val[i]);
	}

	int rp_max = qdata.front();
	for (int i = 0; i < N; ++i) {
		//�ƶ����ڣ��Ƚ���i��Ԫ�س��������У��ٽ���i+K��Ԫ����ӣ����жϴ�ʱ���������е����ֵ�Ƿ��rp_maxС
		qdata.pop(val[i]);
		qdata.push(val[i + K]);
		if (qdata.front() < rp_max)
			rp_max = qdata.front();
	}
	//�����rp_max
	cout << rp_max;

	return 0;
}

*/