#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>t;
        t=s;
        reverse(t.begin(), t.end());
        for(int i=0; i<s.size();i++) s[i]=t[i];
    }
};

int main(){
    Solution s;
    vector<char> v={'h','e','l','l','o'};
    s.reverseString(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}