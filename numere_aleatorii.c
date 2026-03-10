#include <stdio.h>
#include <stdlib.h>

void functie4(int x)
{
    x += 10;
    printf("functie4: x,valoarea: %d,adresa: %p,\n", x, &x);
}
void functie3(int *x)
{
    *x += 5;
    printf("functie3: x, valoare: %d, adresa: %p,\n", *x, x);
    functie4(*x); // folosim * pentru ca functie4 prieste valoarea iar in functia3 este un pointer, x este adresa
    printf("functie3 si 4: x, valoare: %d, adresa: %p,\n", *x, x);
}
void functie2(int *x)
{
    *x += 3;
    printf("functie2: x, valoare: %d, adresa: %p,\n", *x, x);
    functie3(x);
    printf("functie2 si 3: x, valoare: %d, adresa: %p,\n", *x, x);
}
void functie1(int x)
{
    x += 2;
    printf("functie1: x, valoare: %d, adreasa: %p,\n", x, &x);
    functie2(&x); // folosim & pentru ca functia1 are nevoie de un numar intreg fiind prin valoare
    printf("functie1 si 2: x, valoare: %d, adresa: %p,\n", x, &x);
}

int main()
{
    int x = 0;
    printf("x, %d, %p,\n", x, &x);
    functie1(x);
    printf("%d", x);
    return 0;
}
