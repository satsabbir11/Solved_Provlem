#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long a[N], pre[N], suff[N];

void build(int n)
{
    // Initialize the sparse table for the first level
    suff[n + 1] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = max(pre[i - 1], a[i]);
        suff[n - i + 1] = min(suff[n - i + 2], a[n - i + 1]);
    }
}

bool check(int l, int r, int n)
{
    return pre[l] < suff[r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;

        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        build(n);

        string s;
        cin >> s;

        set<int> st;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'L' and s[i + 1] == 'R' and !check(i + 1, i + 2, n))
                st.insert(i + 1);
        }

        for (int kk = 1; kk <= q; kk++)
        {
            long long x;
            cin >> x;
            int xx = x - 1;

            if (s[xx] == 'L')
            {
                s[xx] = 'R'; // RR
                if (s[xx + 1] == 'R' and x < n)
                { // LR

                    auto it = st.find(x);
                    if (it != st.end())
                        st.erase(it);
                }
                if (xx and s[xx - 1] == 'L' and !check(x - 1, x, n))
                    st.insert(x - 1);
            }
            else
            {
                s[xx] = 'L'; // LL

                if (s[xx - 1] == 'L' and xx)
                { // LR

                    auto it = st.find(x - 1);
                    if (it != st.end())
                        st.erase(it);
                }
                if (xx < n - 1 and s[xx + 1] == 'R' and !check(x, x + 1, n))
                    st.insert(x);
            }

            if (st.size())
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}