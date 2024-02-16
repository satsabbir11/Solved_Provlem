vector<int>generateNumberOfPrimeDivisor(int n = 1e6){
    vector<int>primeDivisor(n+1, 0);
    for(int i=2;i<=n;i++){
        if(primeDivisor[i]==0){
            for(int j=i;j<=n;j+=i){
                primeDivisor[j] ++;
            }
        }
    }
    return primeDivisor;
}