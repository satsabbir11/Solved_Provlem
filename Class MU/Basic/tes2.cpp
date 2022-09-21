#include <stdio.h>

int main(){
    char a, b, c;

    scanf("%c", &a);
    scanf("%c", &b);
    scanf("%c", &c);

    if(a<b && a<c){
       printf("%c ",a);
       if(b<c){
        printf("%c ",b);
        printf("%c ",c);
       }
       else{
        printf("%c ",c);
        printf("%c ",b);
       }
    }
    else if(b<a && b<c){
        printf("%c ",b);
        if(a<c){
        printf("%c ",a);
        printf("%c ",c);
       }
       else{
        printf("%c ",c);
        printf("%c ",a);
       }
    }
    else{
        printf("%c ",c);
        if(a<b){
        printf("%c ",a);
        printf("%c ",b);
       }
       else{
        printf("%c ",b);
        printf("%c ",a);
       }
   }
}