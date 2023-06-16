#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m, ans=1;
        cin>>n>>m;
        n--;
        ans += n/m;
        if(n%m) ans++;
        cout<<ans<<endl;
    }
}

/*
The concept is,
1. there is n number of zero
2. u have to fill them with 1 after m period. In other word, there is at least one 1 in every m.
3. ans is minimum

1001001 so here ans = 3
u can say, why 0010010 here ans = 2
but there in the statement [number of one == ceil of(i/m)] from first and last = true, so at the index of 1 and n , u have to 1.


10101 here m = 2

Solution:
1001001
1. so here at first and last index 1 is must,
so ignore 1st index because it is always one.
so ans = 1 by default
so resulting string is 001001

here (n-1)/m = 6/3 = 2
so ans += 2 = 3

another observation is, in last example (n-1)%m == 0 so last index is always 1 ,
what if (n-1)%2 != 0 ?

here u have to add extra one at last by default. so if (n-1)%m==1
ans++;


example: 10010011
1. ignore first index so, resulting string 0010011,
so I fill the last index because 7%3 !=0
*/