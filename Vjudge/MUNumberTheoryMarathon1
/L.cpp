#include <bits/stdc++.h>
using namespace std;

vector<int> generateSumOfDivisor(int n = 2e6)
{
    vector<int> divSum(n + 5, 1);
    divSum[1]=0;
    for (int i = 2; i <= n; i++)
    {
        for(int j=i+i;j<=n;j+=i){
            divSum[j]+=i;
        }
    }
    return divSum;
}

int main()
{
    vector<int> divSum = generateSumOfDivisor();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << divSum[n] << endl;
    }
}