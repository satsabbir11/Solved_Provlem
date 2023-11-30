#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

const int N = 1000000;

vector<bool> isPrime(N + 5);

void getPrime()
{
    isPrime[1] = true;
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

        int st = 0;
        int cnt = 0;

        int ans = n;
        bool f = true;

        while (ans)
        {
            if(!isPrime[ans]){
                cnt++;
                break;
            }else{
                if(st==0){
                    ans--;
                    st=2;
                    cnt++;
                }
                else{
                    ans-=st;
                    st*=2;
                    cnt++;
                }
            }
            if(ans<0){
                f=false;
                break;
            }
        }

        if (f)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
}