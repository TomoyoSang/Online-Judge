#include <iostream>
#include <cstring>

using namespace std;

//ǰ׺��


int nums[11][100001];
int n[11];

int main()
{
	//����׶� ��
	int T = 0;

	int m[5001] = { 0 };
	int  i = 0, j = 0;
	cin >> T;
	int mods[5000] = { 0 };
	mods[0] = 1;

	for (i = 0; i < T; i++)
	{
		cin >> n[i];
		cin >> m[i];
		for (j = 0; j < n[i]; j++)
		{
			cin >> nums[i][j];
		}

	}


	
   //�ж�ʧ�ܺ�

	int currentadd = 0;
	long long flag = 0, k = 0, imod = 0;
	for (k = 0; k < T; k++)
	{
		memset(mods, 0, sizeof(mods));
		mods[0] = 1;
		currentadd = 0;
		flag = 0;
		for (i = 0; i < n[k]; i++)
		{
			currentadd += nums[k][i];
			currentadd = currentadd % (m[k]);
			imod = currentadd % m[k];
			flag += mods[imod];

			mods[imod]++;

		}

		if (k != 0)cout << '\n';
		cout << flag;

	}






	return 0;

}



