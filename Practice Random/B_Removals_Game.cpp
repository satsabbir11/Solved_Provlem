#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        deque<int>a, b;
    
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;

            a.push_back(x);
        }
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;

            b.push_back(x);
        }

        int ff, fe, sf, se;

        bool f=true;

        while(!a.empty() and !b.empty()){
            ff = a.front(), fe = a.back();
            sf = b.front(), se = b.back();

            if((ff!=sf and ff!=se) || (fe!=sf and fe!=se)){
                f=false;
                break;
            }else {
                if(fe==sf) b.pop_front();
                else b.pop_back();
                a.pop_back();}
        }


        cout<<(f?"Bob":"Alice")<<endl;

    }
}