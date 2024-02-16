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