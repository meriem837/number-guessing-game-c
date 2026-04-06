#include <stdio.h>
#include <stdlib.h>  
#include <time.h>

int main() {
    srand(time(0));           
    int M = rand() % 1000 + 1;  

    int n, compteur = 0;
    do {
        printf("Donner une valeur entre 1 et 1000 : ");
        scanf("%d", &n);
        if (n < M) {
            printf("Trop petit !\n");
        }
        else if (n > M) {
            printf("Trop grand !\n");
        }
        compteur++;
    } while (n != M);
    printf("Bravo ! Vous avez fait %d essais.\n", compteur);
    return 0;
}