#define MOD 1000000007
long long Big(long long x, long long n)
{
  long long ans=1;
  while(n>0){
    x%=MOD;
    if(n&1) ans*=x;
    ans%=MOD;
    x*=x;
    n>>=1; 
  }
  return ans;
}