class Solution {
public:
    long long minimumSteps(string s) {
        vector<int>v;
        int z = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1') {v.push_back(i); z++;}
        }

        sort(v.begin(), v.end());
        int cnt = 0;
        for(int i=s.size()-1; i>=(s.size()-z); i--){
            if(s[i]=='0'){
                if(v.size()){
                  cnt+=(i-v[v.size()-1]);
                  v.back();
                }
            }
        }
        return cnt;
    }
};
