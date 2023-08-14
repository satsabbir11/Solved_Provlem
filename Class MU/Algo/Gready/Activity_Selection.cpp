#include <bits/stdc++.h>
using namespace std;

struct Activity{
    int first, second;
};

int main(){
    Activity a[] = {{3, 5}, {1,3}, {5, 8}, { 4, 8}}; // {1,3} {2, 5} {4, 8} {5, 8}
    int n = sizeof(a)/sizeof(a[0]), total_activity = 0;

    sort(a, a+n, [](Activity a, Activity b){
        return a.second < b.second;
    });

    int start = 0;

    for(int i=0;i<n;i++){
        if(a[start].second <= a[i].first){
            total_activity++;
            start = i;
        }
    }
    cout<<total_activity<<endl;
}