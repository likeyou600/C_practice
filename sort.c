#include <stdio.h>
#include <stdlib.h>

int values[4][3] = {{2, 99, 88}, {1, 44, 2}, {90, 80, 70}, {3, 44, 2}};

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    qsort(values, 4, 3 * sizeof(int), compare);
    // array , element count , element size , compare function

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", values[i][j]);
        }
        printf("\n");
    }

    return (0);
}