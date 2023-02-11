#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

// for (auto& x : a) cin >> x;

int main() {
    FastRead

    int t;
    scanf("%d",&t);
    for(int jj=1;jj<=t;jj++) {
        int a[3],k, tot=0;
        for(int i=0;i<3;i++){
            scanf("%d",&a[i]);
            tot+=a[i];
        }
       scanf("%d",&k);

        bool f=false;
        sort(a,a+3);
        long long avg=tot/3;
        
         for(int i=1;i<=3;i++){
            if(abs(avg-a[i])%k==0 && avg%3==0) f=true;
            else f=false;
         }



        if(tot%3==0 && f) printf("Case %d: Peaceful",jj);
        else printf("Case %d: Fight",jj);
    }
}