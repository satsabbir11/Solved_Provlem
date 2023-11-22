#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con(f) (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> p;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, bool>mp;

        for (int i=0;i<m;i++){
            int x;
            cin >> x;
            if(!mp[x]) p.push_back(x); // mainly we take one power because, after summing 2^(x-1) it is impossible to divide by 2^x
            mp[x]=true;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<p.size();j++){ // p size can be at most 32
                int y = pow(2, p[j]);
                
                if(a[i]%y==0){
                    a[i]+= y/2;  // sequentially we add y/2 to every element
                }
            }
        }


        for (int x : a) cout << x<< " ";
        cout << endl;
    }
}
