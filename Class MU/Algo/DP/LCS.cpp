#include <bits/stdc++.h>
using namespace std;

int lcs(string &s, string &t, int n, int m){
    if(!n || !m) return 0;

    if(s[n-1]==t[m-1]) return 1+lcs(s, t, n-1, m-1);
    else return max(lcs(s, t, n-1, m), lcs(s, t, n, m-1));
}

int main()
{
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int n = S1.size();
    int m = S2.size();
 
    cout << "Length of LCS is " << lcs(S1, S2, n, m);
 
    return 0;
}