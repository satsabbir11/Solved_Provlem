#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  long long t;
  cin >> t;
  while (t--)
  {
    long long n;
    cin >> n;

    long long a[n + 2]; a[0] = -1;
    map<long long, long long> mp;

    for (long long i = 1; i <= n; i++)
    {
      cin >> a[i];
      mp[a[i]]++;
    }
    sort(a + 1, a + 1 + n);

    long long past = 0;
    bool f = true;

    for (long i = 1; i <= n; i++)
    {
      if (a[i] - a[i - 1] > 1) //if missing a number
      {
        past = a[i - 1] + 1;
        break;
      }


      if (mp[a[i]] == 1) // no two single frequency number eg: 0 1 1 2 2 3 4 // so loop break in 3 // ans is 2+1 = 3
      {
        if (!f)
        {
          past = a[i];
          break;
        }
        f = false;
      }
      past = a[i] + 1; //ans is always (where we can reach + 1)
    }

    cout << past << endl;
  }
}