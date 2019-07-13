#include <iostream>
#include <cstdio>
//#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
	register int n = 0;
	register char str[55] = { 0 };
	cin >> n;
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		str[i] = (str[i]-'a' + n) % 26 + 'a' ;
	}
	cout << str;

	//system("pause");
	return 0;


}


