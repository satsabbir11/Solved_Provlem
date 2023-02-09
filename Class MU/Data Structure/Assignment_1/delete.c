#include <stdio.h>
#include <string.h>

char final_string[100];

void delete_(char *string, int pos, int length){
    pos--;
    int len = strlen(string), k=0;

    for(int i=0;i<len;i++){
        if(i<pos || pos+length<=i) final_string[k++]=string[i];
    }
}

int main()
{
    char string[] ="Metropolitan";
    delete_(string, 10, 3);
    printf("%s", final_string); // Metropoli
}