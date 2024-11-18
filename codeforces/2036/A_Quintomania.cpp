#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int first;
        scanf("%d", &first);
        int flag = 1;
        for (int i = 1; i < n; i++)
        {
            int w;
            scanf("%d", &w);
            int difference = abs(w - first);
            first = w;
            if (difference == 5 || difference == 7)
            {
                continue;
            }
            flag = 0;
        }
        if (flag == 1)
        {
            printf("YES \n");
        }
        else
        {
            printf("NO \n");
        }
    }
    return 0;
}