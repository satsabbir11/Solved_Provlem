#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        pair<int, int>p[n+2];

        for(int i=1;i<=n;i++){
            int x, y;
            cin>>x>>y;
            p[i].first = x;
            p[i].second = y;
        }

        int w = p[1].first;

        bool f=true;

        for(int i=2;i<=n;i++){
            if(w<=p[i].first && p[i].second>=p[1].second){
                f=false;
                break;
            }
        }
        cout<<(f?w:-1)<<endl;
    }
}