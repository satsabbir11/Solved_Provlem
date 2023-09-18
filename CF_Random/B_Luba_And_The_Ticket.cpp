#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int mn =6;

    for(int i=0;i<10;i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                for(int l =0; l<10; l++){
                    for(int m=0;m<10; m++){
                        for(int n =0; n<10; n++){
                            int diff =((s[0]-'0')!=i) + ((s[1]-'0')!=j) + ((s[2]-'0')!=k) + ((s[3]-'0')!=l) + ((s[4]-'0')!=m) + ((s[5]-'0')!=n);
                            if(i+j+k == l+m+n) mn = min(mn, diff);
                        }
                    }
                }
            }
        }
    }
    cout<<mn<<endl;
}