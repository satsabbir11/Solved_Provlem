#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define fr(i,n)             for (int i=0;i<n;i++)
#define fr1(i,n)            for(int i=1;i<=n;i++)

void solve ()
{

    
   int n, m, q; cin >> n >> m >> q;

   int mm[m];

   fr(i, m) cin >> mm[i];

   sort(mm, mm+ m);

   int qq[q];

   fr(i, q) cin >> qq[i];

   for (int i =0; i< q; i++)
   {

    int x = qq[i];
    int ans =0;


    if (x < *min_element(mm, mm+ m))
    {
        ans = *min_element(mm, mm+ m) - 1;
    }

    else if (x > *max_element(mm, mm + m))
    {
        ans = n - *max_element(mm, mm + m);
    }

    // find the two elements of mm in between which q[i] lies

    else 
    {
        auto it = upper_bound(mm, mm+ m, x); // give me index of m 
        int m1 = *(it -1);
        int m2 = *it;

        

        // auto itt = lower_bound(mm, mm + m, x);
        // int indx2 = distance(mm, itt);

        // cout << indx << " ";

        // int m1 = mm[indx1];
        // int m2 = mm[indx2];

        int xx = (m1 + m2) / 2;

        ans = min(abs(m1 - xx), abs(m2 - xx));


    }


    cout << ans << endl;



   }



}

int main ()
{
    opt();
    int t; cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}