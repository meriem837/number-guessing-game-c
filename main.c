#include <stdio.h>
#define M 500

int main() {
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