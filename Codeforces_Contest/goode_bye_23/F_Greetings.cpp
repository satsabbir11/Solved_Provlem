#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
#define con (f ? "YES" : "NO")
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

#define dpos(n) fixed << setprecision(n)

#define clear1(a) memset(a, -1, sizeof(a))
#define clear0(a) memset(a, 0, sizeof(a))

#define sortn(a, x, n) sort(a + x, a + x + n)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define rsortv(s) sort(s.rbegin(), s.rend())
#define unik(a) unique(a.begin(), a.end()) - a.begin()
#define iotav(s, x) iota(s.begin(), s.end(), x)

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j
#define gap " "

#define auto(x, a) for (auto &x : a)

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

class FenwickTree
{
private:
    vector<int> BIT;

public:
    FenwickTree(int size)
    {
        BIT.resize(size + 1, 0);
    }

    void update(int index, int value)
    {
        index++;
        while (index < BIT.size())
        {
            BIT[index] += value;
            index += (index & -index);
        }
    }

    int query(int index)
    {
        index++; // Convert 0-based index to 1-based index
        int sum = 0;
        while (index > 0)
        {
            sum += BIT[index];
            index -= (index & -index); // Move to the ancestor node
        }
        return sum;
    }

    int rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;

        FenwickTree fenwickTree(1000000005);

        pair<int, int> a[n + 2];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a + 1, a + 1 + n, greater<pair<int, int>>());

        for (int i = 1; i <= n; i++)
        {

            int x, y;
            x = a[i].first;
            y = a[i].second;

            cnt += fenwickTree.rangeQuery(x, y);
            fenwickTree.update(y, 1);
        }

        cout << cnt << endl;
    }
}
