#include <stdio.h>
#include <string.h>

unsigned long long A[2][2] = {{1, 1}, {1, 0}};

void multiply(unsigned long long (*out)[2], unsigned long long (*A)[2], unsigned long long (*B)[2], int size)
{
    unsigned long long temp[size][size];
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    memcpy(out, temp, sizeof(temp));
}

void fast_pow(unsigned long long (*out)[2], int n, int size)
{
    if (n == 1)
    {
        memcpy(out, A, sizeof(A));
        return;
    }

    unsigned long long AK[size][2];
    fast_pow(AK, n / 2, size);
    multiply(AK, AK, AK, size);

    if (n % 2 == 1) // 奇數
        multiply(out, AK, A, size);
    else // 偶數
        memcpy(out, AK, sizeof(AK));
}

unsigned long long calFib(int n)
{
    if (n <= 1)
        return n;

    unsigned long long out[2][2];
    fast_pow(out, n - 1, 2); // F0 為 A , F1 為 A^2
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

    while (scanf("%d%d", &n, &m) != EOF)
    {
        printf("%d\n", calFib(n) % calm(m));
    }
    return 0;
}