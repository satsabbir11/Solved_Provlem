#include <bits/stdc++.h>
using namespace std;

#define Dpos(n) fixed << setprecision(n)


double roof(double d, double h, double x){
    double r = d*(h-x)/h;
    return x*(r+d)/2.0;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        double d, h, ans = 0;
        int n;
        cin>>n>>d>>h;

        int a[n+2];
        for(int i=1;i<=n;i++) cin>>a[i];

        for(int i=1;i<=n;i++){
            if(i!=(n) && (a[i]+h)>a[i+1]){
                ans += roof(d, h, (double) a[i+1]-a[i]);
            }
            else ans += (0.5*d*h);
        }
        cout<<Dpos(7)<<ans<<endl;
    }
}
