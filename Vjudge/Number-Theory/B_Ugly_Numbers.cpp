#include <bits/stdc++.h>
using namespace std;

int main()
{
   set<long long>st;
   st.insert(1);
   long long k=1499;

   while(k--){
    auto it = st.begin();
    long long x = *it;
    st.erase(it);

    st.insert(2*x);
    st.insert(3*x);
    st.insert(5*x);
   }
  
   cout<<"The 1500'th ugly number is "<<*st.begin()<<"."<<endl;
}

