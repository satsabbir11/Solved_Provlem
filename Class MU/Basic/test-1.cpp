#include <stdio.h>

int main(){
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if(a<b && a<c){
       printf("%d ",a);
       if(b<c){
        printf("%d ",b);
        printf("%d ",c);
       }
       else{
        printf("%d ",c);
        printf("%d ",b);
       }
    }
    else if(b<a && b<c){
        printf("%d ",b);
        if(a<c){
        printf("%d ",a);
        printf("%d ",c);
       }
       else{
        printf("%d ",c);
        printf("%d ",a);
       }
    }
    else{
        printf("%d ",c);
        if(a<b){
        printf("%d ",a);
        printf("%d ",b);
       }
       else{
        printf("%d ",b);
        printf("%d ",a);
       }
   }
}