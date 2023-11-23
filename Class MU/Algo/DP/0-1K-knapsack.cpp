#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int *weight, int *profit, int n){
    if(!W || !n) return 0;

    if(weight[n-1]>W) return knapSack(W, weight, profit, n-1);
    else return max(knapSack(W, weight, profit, n-1), profit[n-1] + knapSack(W-weight[n-1], weight, profit, n-1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n);
    return 0;
}