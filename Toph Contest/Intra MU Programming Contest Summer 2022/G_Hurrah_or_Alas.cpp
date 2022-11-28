#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   int cnt=0;
   while(cin>>s){
    int l=s.size();
    for(int i=0;i<l;i++) cnt+=s[i];
   }
   if(cnt%2==0) cout<<"Hurrah!"<<endl;
   else cout<<"Alas!"<<endl;
}