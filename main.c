#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    char replay,hint,history;
    int bestscore = 0;
    FILE *file;

    do{
        printf("====================================\n");
        printf("   #  NUMBER GUESSING GAME  #    \n");
        printf("====================================\n");
        printf("\n");
        printf("Welcome\n");
        printf("\n");
        printf("------------------------------------\n");
        printf("Do you want to see your last 10 scores? \nType (y) Yes | (n) No ");
        scanf(" %c", &history);
        printf("------------------------------------\n");
        if(history=='y'){
            printf("------------------------------------\n");
            printf("# SCORE HISTORY \n");
            printf("------------------------------------\n");
            file = fopen("score.txt", "r");
            if (file == NULL) {
                printf("No previous scores found.\n");
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
                printf("%d  ", scores[j]);
            }
            printf("\n");
            }
            printf("------------------------------------\n");
        }
        printf("------------------------------------\n");
        printf("# BEST SCORE \n");
        printf("------------------------------------\n");

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
printf("------------------------------------\n");

    int level;
    printf("# CHOOSE YOUR DIFFICULTY LEVEL\n");
    printf("[1] Easy : between (1-50) | 10 attempts\n");
    printf("[2] Medium : between (1-100) | 7 attempts\n");
    printf("[3] Hard : between (1-1000) | 5 attempts\n");
printf("------------------------------------\n");
printf("Enter your choice: ");
    scanf("%d", &level);
printf("------------------------------------\n");
printf("# The game has started!\n");
printf("------------------------------------\n");
    int max, attempts;
printf("------------------------------------\n");
    if (level == 1) {
        max = 50;
        attempts = 10;
        printf("# LEVEL 1: EASY\n");
    } else if (level == 2) {
        max = 100;
        attempts = 7;
        printf("# LEVEL 2: MEDIUM\n");
    } else if (level == 3) {
        max = 1000;
        attempts = 5;
        printf("# LEVEL 3: HARD\n");
    } else {
          printf("########################################\n");
          printf("Invalid choice. Please enter 1, 2, or 3.\n");
          printf("########################################\n");
          continue;
    }
    int M = rand() % max + 1;
    int n,compteur,guessed=0;

    for (compteur = 0; compteur < attempts; compteur++) {
        printf("------------------------------------\n");
        printf("Attempt %d / %d\n", compteur + 1, attempts);
        printf("Enter a value between 1 and %d: ", max);
        if (scanf("%d", &n) != 1) {
            printf("########################################\n");
            printf("Invalid input!\n");
            printf("########################################\n");
            while (getchar() != '\n');
            compteur--;
            continue;
        }
        if (n < M) {
            printf("# Too small! \n");
            printf("Need a hint? (y/n):");
            scanf(" %c", &hint);

            if (hint == 'y') {
                printf("------------------------------------\n");
                if (abs(M - n) < 10) {
                    printf("# Hint: you are VERY close! make a small jump\n");
                    } else {
                        printf("# Hint: You are far. Try a bigger jump\n");
                    }
                    printf("------------------------------------\n");
                }
        } else if (n > M) {
            printf("# Too big! \n");
            printf("Need a hint? (y/n):");
            scanf(" %c", &hint);
            if (hint == 'y') {
                printf("------------------------------------\n");
                 if (abs(M - n) < 10) {
                    printf("# Hint: you are VERY close! make a small jump\n");
                    } else {
                        printf("# Hint: You are far. Try a bigger jump\n");
                    }
                    printf("------------------------------------\n");
                }
        } else {
            printf("====================================\n");
            printf("# CONGRATULATIONS #\n");
            printf("====================================\n");
            printf("\n");
            printf("You guessed the number in %d attempts!\n", compteur+1);
            printf("\n");
            guessed=1;
            break;
        }
    }
    if(guessed==0){
        printf("====================================\n");
        printf("# GAME OVER #\n");
        printf("====================================\n");
    printf("The correct number was: %d.\n", M);
    
    }

    int maxScore = 10;
    int score = (attempts - compteur) * maxScore / attempts;
    printf("# Your score: %d / 10 \n", score);
    printf("------------------------------------\n");

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

    printf("------------------------------------\n");
    printf("Do you want to play again?\n");
    printf("(y) Yes | (n) No\n");
    printf("Your choice: ");
    scanf(" %c", &replay);
    printf("------------------------------------\n");
    } while (replay=='y');
    return 0;
}

