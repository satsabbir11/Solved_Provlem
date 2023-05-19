#include <stdio.h>
#include <string.h>

int main(){
    int n, t, k=0;
    scanf("%d", &n);

    char s[n+2][35];
    int cnt[n+2];

    for(int i=0;i<n;i++)  cnt[i]=0;

    for(int i=0;i<n;i++){
        scanf("%s", &s[k]);
        int found =0;

        for(int j=k-1;j>=0;j--){
            if(!strcmp(s[j], s[k])){
                found = 1;
                printf("%s%d\n",s[k],++cnt[j]);
                break;
            }
        }
        if(!found) printf("OK\n",k++);
    }
}