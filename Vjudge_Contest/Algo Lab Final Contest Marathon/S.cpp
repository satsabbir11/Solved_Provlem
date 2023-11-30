#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "yes" : "no")

const int N = 100000;

vector<bool> isPrime(N + 5);

void getPrime()
{
    isPrime[1]=true;
    for (int i = 4; i <= N; i += 2)
        isPrime[i] = true;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (!isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    getPrime();

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        bool f = !isPrime[n];
        cout << con << endl;
    }

    return 0;
}
