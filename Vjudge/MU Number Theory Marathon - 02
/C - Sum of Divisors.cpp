#include <bits/stdc++.h>
using namespace std;
#define loj(i, j) "Case "<<i<<": "<<j

#define MOD 1000000007

long long modGunKoro(long long a, long long b){
    return ((a%MOD)*(b%MOD))%MOD;
}

long long modJogKoro(long long a, long long b){
    return ((a%MOD)+(b%MOD))%MOD;
}

long long csod(long long n)
{
	long long ans = 0;
    long long ans2;
    if(n%2) ans2 = modGunKoro(n, ((n+1)/2));
    else ans2 = modGunKoro((n+1),(n/2));
	for (long long i = 2; i * i <= n; i++)
	{
		long long j = n / i;
		if ((j + i) % 2 == 0)
			ans = modJogKoro(ans, modGunKoro(((j + i) / 2) , (j - i + 1)));
		else
			ans = modJogKoro(ans, modGunKoro((j + i) , ((j - i + 1) / 2)));
		ans = modJogKoro(ans, modGunKoro((j - i),i));
	}
    
	return (ans+ans2+n%MOD-1)%MOD;
}

int main()
{
	long long t=1;
	// cin >> t;
	for (long long i = 1; i <= t; i++)
	{
		long long n;
		cin >> n;

		cout << max(0ll, csod(n)) << endl;
	}
}