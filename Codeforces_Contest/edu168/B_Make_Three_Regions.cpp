#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL
    #include "debug.h"    
#else
    #define print(...)
    #define printt(...)
#endif

#define int long long

void run(){
    
    int n; string s, t;
    cin >> n >> s >> t;

    
    int cnt = 0;
    for( int i = 1 ; i + 1 < n ; i++ ) {
        if(
            (s[i-1] == '.' and s[i] == '.' and s[i+1] == '.' and 
            t[i-1] == 'x' and t[i] == '.' and t[i+1] == 'x')
            or 
            (t[i-1] == '.' and t[i] == '.' and t[i+1] == '.' and 
            s[i-1] == 'x' and s[i] == '.' and s[i+1] == 'x')
        ) {
            cout<<i+1<<endl;
            cnt++;
        }
    }
        
    cout << cnt << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    
    while( t --> 0 ) 
        run();
    
    return 0;
}