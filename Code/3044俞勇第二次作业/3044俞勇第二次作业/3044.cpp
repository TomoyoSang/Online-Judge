#include <iostream>
using namespace  std;

void  calcu(int num);
long long N[1000] = { 0 };
int num;
long long answer = 0;
int i = 0, k = 0;
int main()
{
	cin >> num;
	N[0] = 1;
	N[1] = 1;
	N[2] = 2;
	N[3] = 2;
	
	
	 calcu(num);
	
	
	
	return 0;
		

}
void  calcu(int num)
{
		for (k = 0; k <= num / 2; k++)
		{
			if (N[k] == 0)
			{
				for (i = 0; i <= k / 2; i++)
				{
					N[k] += N[i];
				}
				N[k] = N[k] % 1000000007;
			}
			answer += N[k];
			answer %= 1000000007;
		}
		
		cout<< answer;
		return;
	

		
}

