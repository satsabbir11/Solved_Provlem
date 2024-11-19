#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ordered_set s;
    long long cnt = 0;

    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        s.insert(x);

        long long index = s.order_of_key(x); //index of this number in a set
        cout << index << endl;
    }
}