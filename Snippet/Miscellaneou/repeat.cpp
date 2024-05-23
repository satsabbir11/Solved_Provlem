long long doRepeat(int cur, int plus, int n, bool clockWise=true){
    long long pos;
    if(clockWise) pos =  (cur+plus)%n;
    else pos = (cur-plus+n)%n;
    return pos?pos:n;
}