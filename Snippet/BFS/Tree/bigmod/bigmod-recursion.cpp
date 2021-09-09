long long Big(long long x, long long n)
{
  x%=MOD;
  if(!n) return 1;
  long long ans=Big(x, n/2);
  ans*=ans;
  ans%=MOD;
  if(n&1) ans*=x;
  ans%=MOD;
  return ans;
}