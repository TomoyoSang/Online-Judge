#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	char UFO[100];
	long long group = 1, ride = 1;
	cin >> UFO;
	int len = strlen(UFO);
	for (int i = 0; i < len; ++i)
	{
		ride *= UFO[i] - 'A' + 1;
		ride %= 47;
	}
	
	cin >> UFO;
	 len = strlen(UFO);
	for (int i = 0; i < len; ++i)
	{
		group *= UFO[i] - 'A' + 1;
		group %= 47;
	}

	
	if (ride == group)cout << "GO";
	else cout << "STAY";
	
	//system("pause");
	return 0;

}