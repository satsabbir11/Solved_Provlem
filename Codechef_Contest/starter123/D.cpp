#include<bits/stdc++.h>
using namespace std;


long long getSum(long long n){
    long long sum = (1+n) * (n/2);
    if(n%2==1){
        sum+=(n+1)/2;
    }
    return sum;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, m= 0;
        cin>>n;
        if(n%2==1) m = (n+1)/2;

        long long sum = getSum(n)-1;
        cout<<sum+n<<endl;
    }
}