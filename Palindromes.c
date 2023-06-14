/*
NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA
ABCDEFGHIJK
8M8HH8M8
ASDJDSA
8ZYJLVJLY58
*/
#include <stdio.h>
#include <string.h>
// char *a = "AAE3HHIIJLLJMMOOS2TTUUVVWWXXYYZ500112S3E5Z88";
char a[] = "AAE3HHIIJLLJMMOOS2TTUUVVWWXXYYZ500112S3E5Z88";
int mi(char c, char b)
{
    for (int i = 0; a[i]; i++)
        if (a[i] == c && a[i + 1] == b)
            return 1;
    return 0;
}
// int mi(char c, char b)
// {
//     for (char *temp = a; *temp; temp++)
//     {
//         char first = *temp, second = *++temp;
//         if (first == c && second == b)
//             return 1;
//     }
//     return 0;
// }
int pa(char a, char b)
{
    if (a == b)
        return 1;
    else
        return 0;
}
int main()
{
    char c[500];
    while (gets(c))
    {
        int p = 1, m = 1;
        for (int i = 0, j = strlen(c) - 1; i <= j; i++, j--)
        {
            // printf("%d  %c,%c   ", mi(c[i], c[j]), c[i], c[j]);
            if (pa(c[i], c[j]) != 1)
                p = 0;
            if (mi(c[i], c[j]) != 1)
                m = 0;
        }
        if (p == 1 && m == 1)
            printf("%s -- is a mirrored palindrome.\n\n", c);
        else if (p == 1)
            printf("%s -- is a regular palindrome.\n\n", c);
        else if (m == 1)
            printf("%s -- is a mirrored string.\n\n", c);
        else
            printf("%s -- is not a palindrome.\n\n", c);
    }
    return 0;
}