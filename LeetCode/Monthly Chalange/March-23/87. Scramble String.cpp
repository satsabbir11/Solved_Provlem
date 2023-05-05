#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        return helper(s1,"", s2) || helper("", s1, s2);
    }

private: 
    bool helper(string x, string y, string c)
    {
        cout<<x<<" "<<y<<endl;
        if(x+y==c) return true;
        else{
            int len = x.length();
            int half = len/2;
            for(int i=0; i<len;i++){
                string x1 = x.substr(1, half), x2 = x.substr(half+1, len-half);
                string xx=x2+x1;
                helper(xx,y,c);
                //helper(y,xx,c);
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    string s1, s2;
    cin >> s1 >> s2;

    cout << s.isScramble(s1, s2) << endl;
}