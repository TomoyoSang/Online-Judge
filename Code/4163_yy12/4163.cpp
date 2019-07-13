#include <iostream>
#include <cstdio>

using namespace std;
long long n, m;
long long N[100009] = { 0 };

bool judge(long long _mid)
{
	long long seq__num = 0;
	long long sum = 0;
	for (long long i = 0; i < n; ++i)
	{
		sum += N[i];
		if (sum > _mid)
		{
			sum = N[i];
			seq__num++;
		}
	}
	if (seq__num >= m)//最后是seq_num+1组
		return 0;
	else return 1;
}
long long  _div(long long _left, long long _right)
{
	if (_left > _right)return _right + 1;

	long long _mid = (_left + _right) >> 1;
	if (judge(_mid))
	{
		return _div(_left, _mid - 1);
	}
	else return _div(_mid + 1, _right);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	long long _imax=0,_imin = 0;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> N[i];
		_imax += N[i];
		if (_imin < N[i])_imin = N[i];
	}

	long long ans = _div(_imin, _imax);

	cout << ans;
	return 0;

}