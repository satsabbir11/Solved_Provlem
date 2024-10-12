#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

long long calculateMex(vector<long long> a) {
    sort(a.begin(), a.end()); 

    long long mex = 0;

    for (long long num : a) {
        if (num == mex) {
            mex++;
        } else if (num > mex) {
            break;
        }
    }

    return mex;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin>>n>>k;

        
        vector<long long>a(n+1), b(n+2);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        a[n]=a[n-1];

        long long mex = calculateMex(a);
        //cout<<mex<<endl;
        
        a[n] = mex;

        for(long long i=0;i<=n;i++){
            long long ind = (i+k)%(n+1);
            b[ind] = a[i];
            //cout<<i<<" "<<ind<<endl;
            //cout<<i<<" "<<a[i]<<" "<<ind<<endl;
        }

        for(long long i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        
        cout<<endl;
    }
}