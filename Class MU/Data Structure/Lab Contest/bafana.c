#include <stdio.h>

int main(){
    int t, i;
    scanf("%d", &t);

    for(i=1;i<=t;i++){
        int n,m,k;
        scanf("%d%d%d", &n,&m,&k);

        int ans = (m+(k%n))%n;
        printf("Case %d: %d\n", i, ans?ans:n);
    }
}