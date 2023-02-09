#include <stdio.h>
#include <string.h>

char final_string[100];

void replace(char *string, char *target_string, int pos)
{
    pos--;
    int len1 = strlen(string);
    int len2 = strlen(target_string);

    int i;

    // insert first part of string
    for (i = 0; i < pos; i++)
    {
        final_string[i] = string[i];
    }
    int now = len2, k = 0;

    // replace target_string
    while (now--)
    {
        final_string[i++] = target_string[k++];
    }

    // insert last part if exist after replace
    k = pos + len2;
    if (k < len1)
    {
        for (; i < len1; i++)
        {
            final_string[i] = string[k++];
        }
    }
}

int main()
{
    char string[] = "abcde";
    char target_string[] = "the";

    replace(string, target_string, 2);

    printf("%s", final_string); // athe
}