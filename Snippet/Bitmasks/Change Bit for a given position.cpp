int changeBit(int n, int x){
    n ^= 1<<(x-1); // flip xth bit
    n |= 1<<(x-1); // on xth bit
    if(n&(1<<(x-1))) n ^= 1<<(x-1);  // off xth bit

    return n;
}