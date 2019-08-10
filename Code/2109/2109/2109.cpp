#include <iostream>
#define endl '\n'

using namespace std;

int test_nums[100000];
int target_group[10000][2];
int flag = 0;
void calcu(int i,int left ,int right);
int N;
int K;
int k = 0, l = 0;
long long det = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	int i = 0, j = 0;
	for (i = 0; i < N; i++)
	{
		cin >> test_nums[i];
	}

	
	cin >> K;
	for (i = 0; i < K; i++)
	{
		cin >> target_group[i][0] >> target_group[i][1];
		target_group[i][0] *= target_group[i][0];
		target_group[i][1] *= 4;
	}





	for (i = 0; i < K; i++)
	{
		calcu(i,0, N - 1);

	}
	


	return  0;


}

void calcu(int i,int left,int right )
{

	if (left == right - 1)
	{
		det = (long long)((long long)(target_group[i][0]) - (long long)(test_nums[left]) * target_group[i][1]);
		if (det < 0) { 
			if (i != 0)cout << endl;
			cout << left; return;
		}
		else 
		{
			det = (long long)((long long)(target_group[i][0]) - (long long)(test_nums[right]) * target_group[i][1]);
			if (det < 0) { 
				if (i != 0)cout << endl; 
				cout << left + 1; 
				return;
			}
			else {
				if (i != 0)cout << endl; 
				cout << right + 1; return;
			}
		}
	}
	    int mid = (left + right) / 2;

		det = (long long)((long long)(target_group[i][0]) - (long long)(test_nums[mid]) * target_group[i][1]);
		if (det >= 0)calcu(i, mid,right);
		else calcu(i, left,mid);
	
	
	
	

		return;
}