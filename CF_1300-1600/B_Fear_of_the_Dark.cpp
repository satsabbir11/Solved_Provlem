#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        double px, py, ax, ay, bx, by;
        cin>>px>>py>>ax>>ay>>bx>>by;

        double pa = dist(px, py, ax, ay), oa = dist(ax, ay, 0, 0);
        double pb = dist(px, py, bx, by), ob = dist(bx, by, 0, 0);

        double ab = dist(ax,ay, bx,by)/2.0;

        double ans = 1e9;

        ans = min(ans, max(pa, oa));    //cover single responsiblity
        ans = min(ans, max(pb, ob));

        ans = min(ans, max({ab, pa, ob})); // cover duo responsibily / (pa, ob) or (pb, oa)
        ans = min(ans, max({ab, pb, oa}));

        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
}
