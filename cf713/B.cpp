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
  
   // #ifndef sabbir
   //  freopen("input.txt", "r", stdin); 
   //  freopen("output.txt", "w", stdout);
   //  #endif
 
    long long t;
    cin>>t;
    while(t--)
    {
       long long n,i,l=1,mem1[10],mem2[10],j;
       cin>>n;
       char a[n+2][n+2];
       for(i=1;i<=n;i++)
       {
        for(j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='*')
                {
                    mem1[l]=i;
                    mem2[l]=j;
                    l++;
                }
            }
       }
       //cout<<mem2[1]<<endl;
       // for(i=1;i<=n;i++)
       // {
       //  for(j=1;j<=n;j++)
       //  {
            if(mem1[1]==mem1[2])
                {
                    if(mem1[1]==n)
                    {
                         a[mem1[1]-1][mem2[1]]='*';
                    a[mem1[2]-1][mem2[2]]='*';
                    }
                    else
                    {
                         a[mem1[1]+1][mem2[1]]='*';
                    a[mem1[2]+1][mem2[2]]='*';
                    }
                }
                else if(mem2[1]==mem2[2])
                {
                    if(mem2[1]==n)
                    {
                        a[mem1[1]][mem2[1]-1]='*';
                    a[mem1[2]][mem2[1]-1]='*';
                    }
                    else
                    {
                        a[mem1[1]][mem2[1]+1]='*';
                    a[mem1[2]][mem2[1]+1]='*';
                    }
                }
            else
                {
                    a[mem1[1]][mem2[2]]='*';
                    a[mem1[2]][mem2[1]]='*';
                }
       //  }
       // }
       for(i=1;i<=n;i++)
       {
        for(j=1;j<=n;j++) cout<<a[i][j];
        cout<<endl;
}
    }
   
}