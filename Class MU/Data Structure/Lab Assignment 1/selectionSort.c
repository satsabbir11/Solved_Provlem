#include <stdio.h>

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int minValueIndex = i;
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) minValueIndex = j;
        }
        int tem = a[i];
        a[i] = a[minValueIndex];
        a[minValueIndex] = tem;
    }
}

int main(){
    int a[]={6,5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    selectionSort(a, n);

    for(int i=0;i<n;i++) printf("%d ",a[i]);
}