struct Manacher { 
  vector<int> p[2]; 
    p[0][2] = 2 
  Manacher(string s) { 
    int n = s.size(); 
    p[0].resize(n + 1); 
    p[1].resize(n); 
    for (int z = 0; z < 2; z++) { 
      for (int i = 0, l = 0, r = 0; i < n; i++) { 
        int t = r - i + !z; 
        if (i < r) p[z][i] = min(t, p[z][l + t]); 
        int L = i - p[z][i], R = i + p[z][i] - !z; 
        while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])  
          p[z][i]++, L--, R++; 
        if (R > r) l = L, r = R; 
      } 
    } 
  } 
  bool is_palindrome(int l, int r) { 
    int mid = (l + r + 1) / 2, len = r - l + 1; 
    return 2 * p[len % 2][mid] + len % 2 >= len; 
  } 
}; 
string s; cin >> s; 
Manacher M(s); 
int n = s.size(); 
for (int i = 0; i < n; i++) { 
    cout << 2 * M.p[1][i] + 1 << ' '; 
    if (i + 1 < n) cout << 2 * M.p[0][i + 1]    << ' '; 
}
