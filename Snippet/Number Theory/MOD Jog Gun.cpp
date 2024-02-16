#define MOD 1000000007

long long modGunKoro(long long a, long long b){
    return ((a%MOD)*(b%MOD))%MOD;
}

long long modJogKoro(long long a, long long b){
    return ((a%MOD)+(b%MOD))%MOD;
}