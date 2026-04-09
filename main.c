#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    char replay,hint,history;
    int bestscore = 0;
    FILE *file;

    do{
        printf("do you want to see the history of the 10 lasts scores? y/n \n");
        scanf(" %c", &history);
        if(history=='y'){
            file = fopen("score.txt", "r");
            if (file == NULL) {
                printf("No previous scores.\n");
            }else{
            int scores[10];
            int i = 0, num;
            while (fscanf(file, "%d", &num) == 1) {
                scores[i % 10] = num;  
                i++;
            }
            fclose(file);
            int count;
            if (i < 10) {
                count = i;
            } else {
                count = 10;
            }
            printf("Last %d scores: ", count);
            for(int j=0; j<count; j++){
                printf("%d\t", scores[j]);
            }
            printf("\n");
            }
        }

        file = fopen("best.txt", "r");
        if(file != NULL) {
            fscanf(file, "%d", &bestscore);
            fclose(file);
        }

        if (bestscore == 0) {
    printf("No best score yet.\n");
} else {
    printf("Best score: %d/10\n", bestscore);
}

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
            printf("Too small! (Do you need a hint? enter (y) if yes)\n");
            scanf(" %c", &hint);

            if (hint == 'y') {
                if (abs(M - n) < 10) {
                    printf("you are very close, make a little jump\n");
                    } else {
                        printf("make a bigger jump\n");
                    }
                }
        } else if (n > M) {
            printf("Too big! (Do you need a hint? enter (y) if yes)\n");
            scanf(" %c", &hint);
            if (hint == 'y') {
                 if (abs(M - n) < 10) {
                    printf("you are very close, make a little jump\n");
                    } else {
                        printf("make a bigger jump\n");
                    }
                }
        } else {
            printf("Bravo! You did it in %d attempts.\n", compteur);
            guessed=1;
            break;
        }
    }
    if(guessed==0){
    printf("Game Over! The number was %d.\n", M);
    }

    int maxScore = 10;
    int score = (attempts - compteur) * maxScore / attempts;
    printf("Your score: %d/10 \n", score);

    if(bestscore < score) {
    bestscore = score;
    file = fopen("best.txt", "w");
    if(file != NULL) {
        fprintf(file, "%d", bestscore);
        fclose(file);
    }
}
file = fopen("score.txt", "a");
if(file != NULL) {
    fprintf(file, "%d\n", score); 
    fclose(file);
}


    printf("Do you want to try again? (y)Yes OR (n)No:");
    scanf(" %c", &replay);
    } while (replay=='y');
    return 0;
}

