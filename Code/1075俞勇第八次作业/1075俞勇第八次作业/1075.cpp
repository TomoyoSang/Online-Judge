#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const long long mod = 19301;

long long tree_num[3350] = { 0 };
long long cal_pow[3350] = { 0 };



long long fast_pow(long long a, long long b) {

	long long i_njy = 1, base = a;

	while (b) {

		if (b%2!=0)

			i_njy = (i_njy * base) % mod;

		base = (base * base) % mod;

		b /= 2;

	}

	return i_njy;

}



long long get_zhs(int n, int m) {

	long long temp = (cal_pow[m] * cal_pow[n - m]) % mod;

	temp = fast_pow(temp, mod - 2);

	temp = (cal_pow[n] * temp) % mod;

	return temp;

}



long long cal_tree(int n) {

	if (n == 0)

		return 1LL;

	if (tree_num[n] > 0)

		return tree_num[n];

	long long i_njy = 0;

	for (int i = 0; i < n; ++i) {

		i_njy = (i_njy + cal_tree(n - i - 1) * cal_tree(i)) % mod;

	}

	tree_num[n] = i_njy;

	return i_njy;

}



int main() {

	cal_pow[0] = 1;

	for (long long i = 1LL; i <= 3350LL; ++i) {

		cal_pow[i] = (cal_pow[i - 1] * i) % mod;

	}

	long long n;

	cin >> n;



	long long i_njy = 0;

	for (int i = 0; i <= n; i += 2) {

		i_njy = (i_njy + get_zhs(n, i) * cal_tree(i / 2)) % mod;

	}



	cout << i_njy;



	return 0;

}