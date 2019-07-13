#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const long long mod1_num = (long long)(1e9 + 7);
const long long mod2_num = (long long)(998244353);
const long long mod3_num = (long long)(3000007);

char str[2009] = { 0 };

char substart[2003] = { 0 };
char subend[2003] = { 0 };

long long presum1[2009] = { 0 };
long long presum2[2009] = { 0 };
long long hash_value[mod3_num][2] = { 0 };

int imax(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int bilibili = 0;
	scanf("%s", str);
	scanf("%s %s", substart, subend);
	
	//前缀和
	int len = strlen(str);
	for (int i = 1; i <= len; i++)
	{
		presum1[i] = (presum1[i - 1] * 31 + (str[i-1] - 'a' + 1)) % mod1_num;
		presum2[i] = (presum2[i - 1] * 31 + (str[i-1] - 'a' + 1)) % mod2_num;
	}
	
	//start和end 的两次哈希
	long long hash1_start = 0, hash2_start = 0, hash1_end = 0, hash2_end = 0;
	int start_len = strlen(substart);
	int end_len = strlen(subend);
	for (int i = 0; i < start_len; i++)
	{
		hash1_start = (hash1_start * 31 + (substart[i] - 'a' + 1)) % mod1_num;
		hash2_start = (hash2_start * 31 + (substart[i] - 'a' + 1)) % mod2_num;

	}
	
	for (int i = 0; i < end_len; i++)
	{
		hash1_end = (hash1_end * 31 + (subend[i] - 'a' + 1)) % mod1_num;
		hash2_end = (hash2_end * 31 + (subend[i] - 'a' + 1)) % mod2_num;

	}
	//Plus:31的i次方
	long long pow_1[2003] = { 0 };
	long long pow_2[2003] = { 0 };
	pow_1[0] = 1;
	pow_2[0] = 1;
	for (int i = 1; i < 2000; i++)
	{
		pow_1[i] = (long long)(pow_1[i - 1] * 31) % mod1_num;
		pow_2[i] = (long long)(pow_2[i - 1] * 31) % mod2_num;
	}

	//找开头和结尾
	//找的到就把hash1和hash2的值放进hash1*hash2/mod3_num的位置，有重复就往后移位
	long long cur1 = 0, cur2 = 0;
	long long calcu = 0;
	long long start_cal1 = 0, start_cal2 = 0, end_cal1 = 0, end_cal2 = 0;

	for (int left = 1; left + start_len - 1 <= len; left++)
	{
		start_cal1 = (long long)(presum1[left + start_len - 1] + mod1_num - (long long)(presum1[left - 1] * pow_1[start_len]) % mod1_num) % mod1_num;
		start_cal2 = (long long)(presum2[left + start_len - 1] + mod2_num - (long long)(presum2[left - 1] * pow_2[start_len]) % mod2_num) % mod2_num;
		for (int right = imax(left+start_len-end_len,left); right + end_len - 1 <= len; right++)
		{
			end_cal1 = (long long)(presum1[right + end_len - 1] + mod1_num - (long long)(presum1[right - 1] * pow_1[end_len]) % mod1_num) % mod1_num;
			end_cal2 = (long long)(presum2[right + end_len - 1] + mod2_num - (long long)(presum2[right - 1] * pow_2[end_len]) % mod2_num) % mod2_num;
			if (start_cal1 % mod1_num == hash1_start)
				if (start_cal2% mod2_num == hash2_start)
					if (end_cal1% mod1_num == hash1_end)
						if (end_cal2% mod2_num == hash2_end)
						{
							cur1 = (presum1[right + end_len - 1] + mod1_num - (presum1[left - 1] * pow_1[right + end_len - left]) % mod1_num) % mod1_num;
							cur2 = (presum2[right + end_len - 1] + mod2_num - (presum2[left - 1] * pow_2[right + end_len - left]) % mod2_num) % mod2_num;
							cur1 %= mod1_num;
							cur2 %= mod2_num;
							calcu = (long long)(cur1*cur2) % mod3_num;
								
							while (hash_value[calcu][0] != 0)
							{
								if (hash_value[calcu][0] == cur1 && hash_value[calcu][1] == cur2)break;
								calcu = (calcu + 1) % mod3_num;
							}
							hash_value[calcu][0] = cur1;
							hash_value[calcu][1] = cur2;
						}
		}
	}

	

	//遍历hash_value数组，看有多少个符合条件的
	long long counter = 0;
	for (int i = 0; i < mod3_num; i++)
	{
		if (hash_value[i][0] != 0)counter++;
	}

	printf("%lld", counter);


	return 0;

}