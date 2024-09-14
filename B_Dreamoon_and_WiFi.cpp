#include <bits/stdc++.h>
using namespace std;

#define dpos(n) fixed << setprecision(n)
long long fact[12];

void factorial()
{
    fact[0] = 1;
    for (long long i = 1; i <= 10; i++)
        fact[i] = i * fact[i - 1];
}

long long nCr(long long n, long long r)
{
    if (r > n)
        return 0;
    if(r<0) return 0;
    return fact[n] / (fact[r] * fact[n - r]);
}

int main()
{
    factorial();
    string s1, s2;
    cin >> s1 >> s2;
    long long plus = 0, equilize = 0, hole = 0, need = 0;
    for (auto x : s1)
    {
        if (x == '+')
            plus++;
    }

    for (auto x : s2)
    {
        if (x == '+' or x == '?')
            equilize++;
        if (x == '?')
            hole++;
        if (x == '+')
            need++;
    }

    if (equilize < plus)
        cout << dpos(12) << 0.0 << endl;
    else
    {
        long long ans = nCr(hole, plus - need);
        long long totalCombination = pow(2, hole);
        double cnt = (double)ans / (double)totalCombination;
        cout << dpos(12) << cnt << endl;
    }
}