#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level;
    printf("Choose a difficulty level:\n");
    printf("(1) Easy: between 1 and 50, 10 attempts\n");
    printf("(2) Medium: between 1 and 100, 7 attempts\n");
    printf("(3) Hard: between 1 and 1000, 5 attempts\n");

    scanf("%d", &level);

    int max, attempts;

    if (level == 1) {
        max = 50;
        attempts = 10;
    } else if (level == 2) {
        max = 100;
        attempts = 7;
    } else if (level == 3) {
        max = 1000;
        attempts = 5;
    } else {
        printf("Invalid level.\n");
        return 0;
    }

    srand(time(0));
    int M = rand() % max + 1;

    int n, compteur = 0;

    for (int i = 0; i < attempts; i++) {
        printf("Enter a value between 1 and %d: ", max);

        if (scanf("%d", &n) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        compteur++;

        if (n < M) {
            printf("Too small!\n");
        } else if (n > M) {
            printf("Too big!\n");
        } else {
            printf("Bravo! You did it in %d attempts.\n", compteur);
            return 0;
        }
    }

    printf("Game Over! The number was %d.\n", M);
    return 0;
}

