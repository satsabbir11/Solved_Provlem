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

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

long long getSum(long long n)
{
    long long sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;

    long long sum = 0, number = n;

    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            long long x = i, y = n / i;
            //cout<<x<<" "<<y<<endl;
            long long sum1 = getSum(x), sum2 = getSum(y);
            // cout<<sum1<<" "<<sum2<<endl;
            if (sum < max(sum1, sum2))
            {
               // cout<<sum1<<" "<<sum2<<endl;
                sum = max(sum1, sum2);
                //cout<<sum<<endl;
                if (sum1 == sum2)
                    number = min(x, y);
                else
                {
                    if (sum == sum1)
                        number = x;
                    else
                        number = y;
                }
                // cout<<x<<" "<<y<<endl;
                // cout<<"h "<<number<<endl;
            }
            else if (sum == max(sum1, sum2))
            {
                if (sum1 == sum2)
                    number = min({number, x, y});
                else
                {
                    //cout<<number<<" "<<x<<" "<<y<<" "<<sum1<<" "<<sum2<<endl;
                    if (sum == sum1)
                        number = min(number, x);
                    else if(sum==sum2)
                        number = min(number, y);
                }
            }
        }
    }
    cout << number << endl;
}