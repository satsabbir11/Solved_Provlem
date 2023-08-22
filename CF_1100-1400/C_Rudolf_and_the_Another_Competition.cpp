#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long f;
    cin >> f;



    for(int t=1;t<=f;t++)
    {
        long long n, m, h, ans = 1;
        cin >> n >> m >> h;

         long long firstScore = 0, firstPenalty = 0;


        for (long long i = 0; i < n; i++)
        {
        
            long long a[m];
            for (long long j = 0; j < m; j++) cin >> a[j];
            sort(a, a+m);

            long long penalty = 0, time = 0, count = 0;

            for(long long j=0;j<m;j++)
            {
                if(time + a[j] <= h)
                {
                    time += a[j];
                    penalty += time;
                    count++;
                }
                else break;
            }

           
            if(i == 0) {
                firstScore = count;
                firstPenalty = penalty;
            }
            else
            {
                if(count > firstScore) {
                    ans ++;
                }
                else if(count == firstScore)
                {
                    if(penalty < firstPenalty) ans++;
                }
            }
        }
        cout << ans << endl;
    }
}