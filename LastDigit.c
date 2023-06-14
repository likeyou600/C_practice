/*
72
20
72
97
81
11
1
2
3
655065
97998522672982898714929429711424123829332777395272386873946613187314322124721962771
0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pows(int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= n;
        ans = ans % 10;
    }

    return ans;
}

int main()
{
    int table[101];
    for (int i = 1; i <= sizeof(table) / sizeof(int); i++)
    {
        int ans = 0;
        for (int j = 1; j <= i; j++)
        {
            ans += pows(j);
        }

        table[i] = ans % 10;
    }
    char cinput[9999];
    while (scanf("%s", cinput) != EOF)
    {
        int input = 0;
        if (strlen(cinput) <= 3)
            input = atoi(cinput);
        else
            input = atoi(cinput + strlen(cinput) - 3);

        if (input == 0)
            break;

        printf("%d\n", table[input % 100]);
    }
}
