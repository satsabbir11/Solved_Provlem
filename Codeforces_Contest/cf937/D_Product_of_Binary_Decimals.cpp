#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
#define con (f ? "YES" : "NO")
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

bool isBinary(int n)
{
    while (n)
    {
        if (n % 10 > 1)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> p;

    for (int i = 10; i <= 100000; i++)
    {
        if (isBinary(i))
            p.push_back(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        bool f = false;

        // for(int i=0;i<10;i++) cout<<p[i]<<" ";
        // cout<<endl;

        // continue;

        int m = 1000;

        while (m--)
        {
            int tem = n;
            for (int i = 0; i < p.size(); i++)
            {
                if (n % p[i] == 0)
                {
                    while (n % p[i] == 0 and n > 1)
                        n /= p[i];
                    i = 0;
                    // cout<<p[i]<<endl;
                }
                if (isBinary(n))
                {
                    f = true;
                    break;
                }
            }
            if (tem == n)
                break;
        }

        if (isBinary(n))
        {
            f = true;
        }

        // cout<<n<<endl;

        cout << con << endl;
    }
}