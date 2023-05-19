#include <stdio.h>

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);

    int rem = 240 - t;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int cur = 5 * i;
        if (rem >= cur)
        {
            ans++;
            rem -= cur;
        }
        else
        {
            printf("%d", ans);
            return 0;
        }
    }
    printf("%d", ans);
}