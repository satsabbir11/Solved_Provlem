#include<bits/stdc++.h>
using namespace std;

void insertionSort(int *a, int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(a[j]>key && j>=0){ // if you find a number greater than key just move that number rightward
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int a[] ={5,4,3,2,1};
   int n = sizeof(a)/sizeof(a[0]);
   insertionSort(a, n);
   for(int i=0;i<n;i++) cout<<a[i]<<" ";
}