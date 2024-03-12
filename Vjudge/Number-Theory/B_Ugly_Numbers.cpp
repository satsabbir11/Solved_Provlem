#include <bits/stdc++.h>
using namespace std;
set<long long> v;

int main()
{
   long long kk=0;
   set<long long>st;
   for(int i=0;i<=15;i++){
    for(int j=0;j<=15;j++){
        for(int k=0;k<=15; k++){
            long long number = pow(2, i)*pow(3, j)*pow(5, k);
            st.insert(number);
            if(kk==20000) break;
        }
        if(kk==20000) break;
    }
     if(kk==20000) break;
   }

   kk=1;

   for(auto x: st){
    if(kk==1501){
        kk=x;
        break;
    }
    kk++;
   }
   cout<<"The 1500'th ugly number is "<<kk<<"."<<endl;
}
