// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> a(n), pre(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             pre[i+1] += a[i];
//             if (i)
//                 pre[i+1] += pre[i];
//         }
       
//         for (int i = 0; i < n; i++)
//             cout << pre[i+1] << " ";
//         cout << endl;
        

//         int ans[n + 2];

//         for (int i = 1; i <= n; i++)
//         {
//             int r = i-1 , l = 1, mid;
//             // ans[i] = INT_MAX;
//             // while (l < r)
//             // {
//             //     mid = l + (r - l) / 2;
//             //     // cout<<l<<" "<<r<<" "<<i<<" "<<mid<<" "<<pre[mid] - pre[i]<<endl;
//             //     if (pre[i] - pre[mid-1] > a[i])
//             //     {
//             //         l = mid;
//             //         ans[i] = min(ans[i], i-mid);
//             //     }
//             //     else
//             //         r = mid-1;
//             // }
//             r = n , l = i+1;

//             while (l < r)
//             {
//                 mid = l + (r - l) / 2;
//                 // cout<<l<<" "<<r<<" "<<i<<" "<<mid<<" "<<pre[mid] - pre[i]<<endl;
//                 if (pre[mid] - pre[i] > a[i])
//                 {
//                     r = mid;
//                     ans[i] = min(ans[i], mid-i);
//                 }
//                 else
//                     l = mid+1;
//             }
//             // cout<<l<<" "<<r<<" "<<i<<" "<<mid<<" "<<pre[mid] - pre[i]<<endl;
//         }
//        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
//        cout << endl;
//     }
// }

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> ans(n, n);
    for (int z = 0; z < 2; ++z) {
      vector<long long> s(n + 1);
      for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
      vector<int> p(n, -1);
      for (int i = 1; i < n; ++i) {
        int j = (z ? n - i - 1 : i);
        int l = 1, r = i;
        while (l <= r) {
          int m = (l + r) / 2;
          if (s[i] - s[i - m] > a[i] && p[i - 1] >= i - m) {
            ans[j] = min(ans[j], m);
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
        if (a[i - 1] > a[i]) ans[j] = 1;
        p[i] = (a[i] == a[i - 1] ? p[i - 1] : i - 1);
      }
      reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; ++i)
      cout << (ans[i] == n ? -1 : ans[i]) << ' ';
    cout << '\n';
  }
}