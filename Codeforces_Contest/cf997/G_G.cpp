#include <bits/stdc++.h>
using namespace std;

double getAns(double x, double y, double mid){
    double xx = sqrt((x*x)-(mid*mid));
    double yy = sqrt((y*y)-(mid*mid));

    return (xx*yy)/(xx+yy);
}

int main(){
    int t, ll=1;
    cin>>t;

    while(t--){
        double x, y, w; cin>>x>>y>>w;
        double l = 0.0, r = min(x, y);
        int cnt=100;

        while(cnt--){
            double mid = (l+r)/2.0;
            if(getAns(x, y, mid)>w) l=mid;
            else r=mid;
        }

        cout<<"Case "<<ll++<<": "<<fixed<<setprecision(10)<<l<<endl;
    }

}