#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int in, en, dr;
   
    while (t--)
    {
        in = en = dr = 0;
        for (int i = 0; i < 5; i++)
        {
            int x;
            scanf("%d", &x);
            if (x == 1)
                in++;
            else if (!x)
                dr++;
            else
                en++;
        }
        if(in==en) printf("DRAW\n");
        else if(in>en) printf("INDIA\n");
        else printf("ENGLAND\n");
    }
}