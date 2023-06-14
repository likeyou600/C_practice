/*
 11 7
11 6
7 0
7 1
7 2
7 3
2147483647 19  9515  0

out 325917
*/
#include <stdio.h>
#include <string.h>
int A[2][2] = {{1, 1}, {1, 0}};

int (*multiply(int (*A)[2], int (*B)[2]))[2]
{
    printf("123\n");

    static int out[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                out[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return out;
}
int (*fast_pow(int n))[2]
{

    if (n == 1)
        return A;
    if (n % 2 == 1) // 奇數
    {

        int(*AK)[2] = fast_pow(n / 2);

        return multiply(AK, AK);
    }
    else
    { // 偶數
        int(*AK)[2] = fast_pow((n - 1) / 2);

        return multiply(multiply(A, AK), AK);
    }
}
int calFib(int n)
{
    if (n <= 1)
        return n;
    int(*out)[2] = fast_pow(n / 2);
    return out[0][0];
}
int calm(int m)
{
    if (m == 0)
        return 1;
    return calm(m - 1) * 2;
}

int main()
{

    int n, m;
    // while (scanf("%d%d", &n, &m) != EOF)
    // {
    //     printf("%d , %d\n", calFib(n), calm(m));
    // }

    printf("%d , %d\n", calFib(10), calm(6));
}