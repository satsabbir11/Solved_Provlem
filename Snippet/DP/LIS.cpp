int LIS(vector<int>&v){
    int l = v.size(), dp[l];
    for(int i=0; i<l;i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(v[j]<v[i] and dp[i]<dp[j]+1) dp[i] = dp[j] + 1;
        }
    }
    return *max_element(dp, dp+l);
}