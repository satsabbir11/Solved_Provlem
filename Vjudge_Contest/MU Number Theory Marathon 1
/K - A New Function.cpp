#include <bits/stdc++.h>
using namespace std;
#define loj(i, j) "Case "<<i<<": "<<j
long long csod(long long n)
{
	long long ans = 0;
	for (long long i = 2; i * i <= n; i++)
	{
		long long j = n / i;
		if ((j + i) % 2 == 0)
			ans += ((j + i) / 2) * (j - i + 1);
		else
			ans += (j + i) * ((j - i + 1) / 2);
		ans += (j - i)*i;
	}
	return ans;
}

int main()
{
	long long t;
	cin >> t;
	for (long long i = 1; i <= t; i++)
	{
		long long n;
		cin >> n;

		cout << loj(i, max(0ll, csod(n))) << endl;
	}
}