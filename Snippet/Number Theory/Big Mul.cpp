long long bigMul(long long n, long long m, long long p)
{
  if(m<=0) return 0;
    long long res = bigMul(n, m/2, p);
    long long ans = (2*res)%p;
    if(m%2) ans = (ans+n)%p;
    return ans;
}