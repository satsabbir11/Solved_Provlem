#include <stdio.h>
#include <string.h>

char sub_string[100];

void substring(char *string, int start, int length){
    int k= 0;
    for(int i=start-1;i<start+length-1;i++){
        sub_string[k++]=string[i];
    }
}

int main()
{
    char string[] ="Metropolitan";
    substring(string, 2, 3);
    printf("%s", sub_string); // etr
}