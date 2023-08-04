#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k, ans = 0;
        cin>>n>>k;


        for(int lastPrev=n; lastPrev>=1; lastPrev--){
            bool isValid = true;
            int second = n;
            int first = lastPrev;

            for(int j=1;j<=k-2;j++){
                int tem = first;
                first = second - first;
                second = tem;

                isValid &= (first<=second && first>=0);
                if(!isValid) break;
            }
           if(isValid) ans++;
        }
        cout<<ans<<endl;
    }
}
