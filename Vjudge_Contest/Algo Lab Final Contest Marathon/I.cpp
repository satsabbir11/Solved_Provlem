#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int x2;
    cin >> x2;

    // find the biggest prime of every number j divide by prime i
    vector<int> prime(x2+5);
    for (int i = 2; i <= x2; i++)
    {
        if (!prime[i])
        {
            for (int j = i * 2; j <= x2; j += i)
                prime[j] = i;
        }
    }


    //find the number, between x2's biggest prime and x2, who's biggest prime is smallest one of all
    int x0 = x2;
    for(int i = x2-prime[x2]+1;i<=x2;i++) x0 = min(x0, i-prime[i]);

    //x0 is not prime
    cout<<x0+1<<endl;
}