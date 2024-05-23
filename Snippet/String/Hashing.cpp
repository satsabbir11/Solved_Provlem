const long long MOD = 999999999999999989, MOD1=1000001137;
long long base = 7919,base1= 2551, base2 = 6091;
void pre_power()
{
    pw[0] = 1;
    for(int i = 1; i < 300015; i++)
        pw[i] = (pw[i - 1] * base) % MOD;
}
long long get_hashval(string str)
{
    int len=str.length();
    long long hash_val=0;
    for(int i = 0; i < len; i++)
    {
        hash_val=((hash_val*base)+str[i])%MOD;
        HASH[i+1]=hash_val;
    }
    return hash_val;
}
long long SubstringHash(int l, int r)
{
    return (HASH[r]-(HASH[l-1]*pw[r-l+1]) %
            MOD + MOD) % MOD;
}