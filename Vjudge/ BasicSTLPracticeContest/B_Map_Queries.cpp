#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    map<string, int> mp;
    while (t--)
    {
        int type;
        string s;
        cin >> type>>s;;
        if (type == 1){
            int x; cin>>x;
            mp[s]+=x;
        }
        else if (type == 2)
            mp.erase(s);
        else
        {
            map<string, int>::iterator itr = mp.find(s);
            if (itr == mp.end())
                cout << 0 << endl;
            else
                cout << mp[s] << endl;
        }
    }
}