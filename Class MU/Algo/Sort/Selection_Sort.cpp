#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

void selectionSort(int *a, int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;      // point on first element
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                minIndex = j; // find minimum index respect to a[i]
            }
        }
        swap(a[i], a[minIndex]); // swap minimum number to a[i]
    }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int a[] ={5,4,3,2,1};
   int n = sizeof(a)/sizeof(a[0]);
   selectionSort(a, n);
   for(int i=0;i<n;i++) cout<<a[i]<<endl;
}