#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define dpos(n) fixed << setprecision(n)

double getX(double x1, double y1, double x2, double y2){
    double x = x1-x2; x*=x;
    double y = y1-y2; y*=y;
    return sqrt(x+y);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
        long long n;
        cin>>n;

        double tx, ty, x, y, cnt=0;

        for(long long i=1;i<=n;i++){
            cin>>x>>y;
            if(i==1) cnt+=getX(0, 0, x, y);
            else cnt+=getX(tx, ty, x, y);
            tx=x;
            ty=y;
        }
        cnt+=getX(tx, ty, 0, 0);

        cout<<dpos(6)<<cnt<<endl;
    
}


