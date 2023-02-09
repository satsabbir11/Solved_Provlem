#include <stdio.h>
#include <string.h>

char final_string[100];

void insert(char *string, char *target_string, int pos)
{
    pos--;
    int len1 = strlen(string);
    int len2 = strlen(target_string);

    int i;
    
    //insert first part of string
    for (i = 0; i < pos; i++)
    {
        final_string[i] = string[i];
    }
    int now = len2, k = 0;

    //insert target_string
    while (now--)
    {
        final_string[i++] = target_string[k++];
    }
    k = pos;

    //insert last part of string
    for (; i < len1 + len2; i++)
    {
        final_string[i] = string[k++];
    }

}

int main()
{
    char string[] = "father their";
    char target_string[] = "the";

    insert(string, target_string, 7);

    printf("%s", final_string); // fatherthe their
}