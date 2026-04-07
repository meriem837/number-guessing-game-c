#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    char replay;
    do{
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
         printf("Invalid level, You should enter a the number of the level you want.\n");
        continue;
    }
     
    int M = rand() % max + 1;
    int n, compteur = 0,guessed=0;

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
            guessed=1;
            break;
        }
    }
    if(guessed==0){
    printf("Game Over! The number was %d.\n", M);
    }
    printf("Do you want to try again? (y)Yes OR (n)No:");
    scanf(" %c", &replay);
    } while (replay=='y');
    return 0;
}

