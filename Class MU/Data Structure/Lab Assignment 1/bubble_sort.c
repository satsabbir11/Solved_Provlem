#include <stdio.h>

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int tem = a[j];
                a[j] = a[j+1];
                a[j+1] = tem;
            }
        }
    }
}

int main(){
    int a[]={5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);

    for(int i=0;i<n;i++) printf("%d ",a[i]);
}