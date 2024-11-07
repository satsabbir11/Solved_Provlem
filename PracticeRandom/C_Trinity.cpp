#include <bits/stdc++.h>
using namespace std;



void run(){
    
    int n;
    cin >> n;
    vector<int>a(n);
    
    for(auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    int ans = 0;
    for( int i = 0 ; i + 1 < n ; i++ ) {
        int target = a[i] + a[i + 1];

        int pos = lower_bound(a.begin(), a.end(), target) - a.begin();

        cout<<pos+1<<" "<<pos-i<<endl;

        ans = max(ans, pos - i);
    }
    
    cout << n-ans << endl;
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
