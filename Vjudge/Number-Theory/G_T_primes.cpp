#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

bool prime[N + 5];

int main()
{
    prime[1]=true;
    for (int i = 2; i * i <= N; i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= N; j += i)
                prime[j] = true;
        }
    }
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int sq = sqrt(n);
        if ((long long)sq * (long long)sq == n and !prime[sq])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}