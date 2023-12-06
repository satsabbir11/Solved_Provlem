#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

#define MOD 1000000007

vector<long long> calculateAndStoreValues(long long n) {
    vector<long long> result;
    result.reserve(n + 1);

    for (long long k = 1; k <= n; ++k) {
        long long sum = 0;
        for (long long i = k; i <= n; ++i) {
            sum = (sum+ i)%MOD;
        }
        result.push_back(sum);
    }

    return result;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
   
    vector<long long> values = calculateAndStoreValues(10005);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        sort(s.begin(), s.end());

        s+='0'+s;
        long long ans = 0;

        for(int i=1;i<=n;i++){
            if(s[i]!=s[i-1]){
                int g = n-i-1;
                ans+=g+1;
                g--;
                ans+=values[g];
            }
        }

        cout<<ans<<endl;
    }
}