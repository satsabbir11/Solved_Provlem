#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    int n= s.size();

    bool f=true;

    for(int i=0;f && i<n;i++){
        if((i+2)<n && s[i]=='1' && s[i+1]=='4' && s[i+2]=='4') i+=2;
        else if((i+1)<n && s[i]=='1' && s[i+1]=='4') i++;
        else if(s[i]!='1') f=false;
    }

    cout<<con<<endl;
}