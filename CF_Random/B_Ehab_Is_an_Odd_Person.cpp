#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    bool mp[2];


    int a[n+2];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        mp[a[i]%2]=true;
    }

    if(mp[1] && mp[0]) sort(a, a+n);

    for(int i=0;i<n;i++) printf("%d ", a[i]);
}