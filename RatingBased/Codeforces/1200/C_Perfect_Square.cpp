#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0, fnt = 0;
        cin >> n;
        char s[n+2][n+2];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> s[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(s[i][j]!=s[n+1-j][i]) cnt++;
            }
        }
    
        cout << cnt/2 << endl;
    }
}