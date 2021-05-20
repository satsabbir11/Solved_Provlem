#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pi acos(-1)
#define endl "\n"
#define ull unsigned long long

#define inf 10002


int main()
{
    FastRead;
  
//    #ifndef sabbir
//     freopen("/CP_OJ/input.txt", "r", stdin); 
//     freopen("/CP_OJ/output.txt", "w", stdout);
//     #endif

    long long t;
    cin>>t;
    while(t--)
    {
        long long n,i,sm,st;
        cin>>n;
        string s;
        cin>>s;
        vector<long long>t,m;
        for(i=0;i<n;i++)
        {
            if(s[i]=='T') t.push_back(i);
            else m.push_back(i);
        }
        sm=m.size();
        st=t.size();
        if(sm*2!=st) cout<<"NO"<<endl;
        else{
            for(i=0;i<sm;i++)
            {
                if(t[i]>m[i] || t[i+sm]<m[i])
                {
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(i==sm) cout<<"YES"<<endl;
        }
    }
   
}