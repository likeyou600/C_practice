/*
 ER STR YJR EPT;F
 ER STR YJR EPT;F
*/
#include <stdio.h>
char table[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char getnew(char old)
{
    if (old == ' ')
        return ' ';

    for (int i = 0; table[i]; i++)
    {
        if (old == table[i])
        {
            return table[i - 1];
        }
    }
}

int main()
{
    char input[999];
    while (gets(input))
    {
        for (int i = 0; input[i]; i++)
        {
            printf("%c", getnew(input[i]));
        }
        printf("\n");
    }
    return 0;
}
