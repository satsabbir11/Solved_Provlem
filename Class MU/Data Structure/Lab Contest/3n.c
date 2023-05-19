#include <stdio.h>

int a, b;

void swap(){
    if(a>b){
        int tem =a;
        a=b;
        b=tem;
    }
}

int main()
{
    while (scanf("%d%d", &a, &b) != EOF)
    {
        int i = a;
        int j = b;
        swap();
        int mx =0;

        for(int i=a;i<=b;i++){
            int n=i;
            int cnt=0;
            while(n!=1){
                if(n%2) n = 3*n+1;
                else n/=2;
                cnt++;
            }
            if(cnt>mx) mx=cnt;
        }
        printf("%d %d %d\n", i, j, mx+1);
    }
}