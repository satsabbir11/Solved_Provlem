bitset<MAX>bs;
bool check(int sum) { bs.reset(); bs[0]=1;
for(int i=1;i<=n;i++) bs |= bs << arr[i]; return bs[sum]; }