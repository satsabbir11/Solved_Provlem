#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt[6]={};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==4) cnt[0]++;
        else if(x==8 && cnt[0]>cnt[1]) cnt[1]++;
        else if(x==15 && cnt[1]>cnt[2]) cnt[2]++;
        else if(x==16 && cnt[2]>cnt[3]) cnt[3]++;
        else if(x==23 && cnt[3]>cnt[4]) cnt[4]++;
        else if(x==42 && cnt[4]>cnt[5]) cnt[5]++;
    }

    sort(cnt, cnt+6);
    cout<<n-6*cnt[0]<<endl;
}