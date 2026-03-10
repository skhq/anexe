#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    float V[5][5], A[5][2];
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            V[i][j] = rand() % 100;
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%.2f ", V[i][j]);
        printf("\n");
    }

    for (j = 0; j < 5; j++)
    {
        float min = V[0][j];
        float max = V[0][j];
        for (i = 0; i < 5; i++)
        {
            if (V[i][j] < min)
                min = V[i][j];
            if (V[i][j] > max)
                max = V[i][j];
        }
        A[j][0] = min;
        A[j][1] = max;
    }

    printf("\n");

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            V[i][j] = 2 * (V[i][j] - A[j][0]) / (A[j][1] - A[j][0]) - 1;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%.2f ", V[i][j]);
        printf("\n");
    }

    return 0;
}