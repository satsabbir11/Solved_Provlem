#include <bits/stdc++.h>
using namespace std;

int partition(int low, int high, int *a){
    int index = low-1;
    for(int i=low; i<high; i++){
        if(a[i]<=a[high]) swap(a[i], a[++index]);
    }
    swap(a[high], a[++index]);
    return index;
}

void quick_sort(int low, int high, int *a){
    if(low<high){
        int pi = partition(low, high, a);
        quick_sort(low, pi-1, a);
        quick_sort(pi+1, high, a);
    }
}

int main(){
    int a[] = {5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort(0, n-1, a);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}