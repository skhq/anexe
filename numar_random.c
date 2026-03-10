#include <stdio.h>
#include <stdlib.h> // Pentru rand() si srand()
#include <time.h>   // Pentru time()

int main() {
    srand(time(NULL)); 

    printf("Generam 3 numere aleatorii intre 20 si 39:\n");

    for(int i = 0; i < 3; i++) {
        int numar = 20 + rand()%100;
        printf("Numarul %d este: %d\n", i + 1, numar);
    }

    return 0;
}
