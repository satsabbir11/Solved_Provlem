#include<bits/stdc++.h>
using namespace std;

set<int>allElement, imidiateSenior;

bool isPossible(int x){
    if(allElement.empty()) return false;
    if(*allElement.begin()>x) return false;
    if(!imidiateSenior.empty() && *imidiateSenior.begin()<x) return false;
    return true;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        allElement.clear();
        imidiateSenior.clear();
        
        long long n;
        cin>>n;
        
        int ans = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(isPossible(x)){
                ans++;
                imidiateSenior.insert(x);
            }
            allElement.insert(x);
        }
        cout<<ans<<endl;
    }
}