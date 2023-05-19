#include <stdio.h>
#include <string.h>

int main()
{
    char s[1005];
    scanf("%s", &s);
    if(s[0]>'Z') s[0]=s[0]-('a'-'A');
    printf("%s", s);
}