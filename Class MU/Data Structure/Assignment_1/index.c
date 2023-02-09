#include <stdio.h>
#include <string.h>

char sub_string[100];

int index_(char *string, char *target_string){
    int len1 = strlen(string);
    int len2 = strlen(target_string);


    for(int i=0;i<(len1-len2);i++){
        int k=0, cnt=0;

        //checking string match or not
        for(int j=i;j<(i+len2);j++){
            if(string[j]==target_string[k++]) cnt++;
        }

        //if match then
        if(cnt==len2){
            return i;
        }
    }
    return -1;
}

int main()
{
    char string[] ="father their";
    char target_string[]="the";
    
    printf("%d", index_(string, target_string)); // 2
}