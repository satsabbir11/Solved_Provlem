#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    set<int> st;
    while (t--)
    {
        int type, n;
        cin >> type >> n;
        if (type == 1)
            st.insert(n);
        else if (type == 2)
            st.erase(n);
        else
        {
            set<int>::iterator itr = st.find(n);
            if (itr == st.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}