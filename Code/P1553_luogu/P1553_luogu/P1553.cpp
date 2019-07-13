#include <iostream>
#include <cstdio>
#include <cstring>



using namespace std;

int main()
{
	char _str[50] = { 0 };
	cin.getline(_str, 50,'\n');
	int len = strlen(_str);

	int flag = 0;
	int pos = 0;
	bool if_zero = 1;
	for (int i = 0; i < len; ++i)
	{
		if (_str[i] == '.')
		{
			flag = 1;
			pos = i;
		}
		else if (_str[i] == '/')
		{
			flag = 2;
			pos = i;
		}
		else if (_str[i] == '%')
		{
			flag = 3;
			pos = len - 1;
		}
	}

	if (flag == 0)
	{
		
		for (int i = len - 1; i >= 0; i--)
		{
			if (if_zero == 1 && _str[i] == '0')
			{
				continue;
			}
			else
			{
				if_zero = 0;
			}
			printf("%c", _str[i]);
		}
		
		
	}
	else if (flag == 1)
	{
		for (int i = pos - 1; i >= 0; --i)
		{
			if (if_zero == 1 && _str[i] == '0')
			{
				continue;
			}
			else
			{
				if_zero = 0;
			}
			printf("%c", _str[i]);
		}
		printf("%c", '.');
		int counter = pos + 1;
		while (_str[counter] == '0')counter++;
		for (int i = len - 1; i > counter; --i)
		{
			
			printf("%c", _str[i]);
		}
		if (_str[counter] != '0')printf("%c", _str[counter]);
	}
	else if (flag == 2)
	{
		for (int i = pos - 1; i >= 0; --i)
		{
			if (if_zero == 1 && _str[i] == '0')
			{
				continue;
			}
			else
			{
				if_zero = 0;
			}
			printf("%c", _str[i]);
		}
		printf("%c", '/');
		int counter = pos + 1;
		while (_str[counter] == '0')counter++;
		for (int i = len - 1; i > counter; --i)
		{

			printf("%c", _str[i]);
		}
		if (_str[counter] != '0')printf("%c", _str[counter]);

	}
	else if (flag == 3)
	{
		if_zero = 1;
		for (int i = pos - 1; i >= 0; --i)
		{
			if (if_zero == 1 && _str[i] == '0')
			{
				continue;
			}
			else
			{
				if_zero = 0;
			}
			printf("%c", _str[i]);
		}
		printf("%c", '%');
	
	}
	
	return 0;
}