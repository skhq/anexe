#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generatePuzzle()
{
    int i, n;
    printf("introduceti un numar n patrat perfect ");
    scanf("%d", &n);
    if ((int)sqrt(n) * (int)sqrt(n) != n)
    {
        printf("numarul nu este patrat perfect");
        return;
    }
    printf("generam numere de la 0 la %d\n", n);
    int arr[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    srand(time(NULL));

    // Fisher-Yates Shuffle
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int size = (int)sqrt(n);
    int count = 0;
    // Now put those numbers into your 2x2 matrix
    int matrix[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = arr[count++];
        }
    }

    // Calculate the width of the largest number for spacing
    int width = 0;
    while (n)
    {
        width++;
        n /= 10;
    }

    // Print it
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 0)
                printf("%*s ", width, "-");
            else
                printf("%*d ", width, matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    generatePuzzle();

    return 0;
}