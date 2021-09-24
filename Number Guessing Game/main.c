#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Number Guessing Game:
- implement using a small state machine that runs on a while loop.
    - state 0, main menu
    - state 1, play game
    - state 2, settings (change max number)
    - state 3, quit
- any state can quit by typing 'exit' as input
- take user input as int and use comparisons to decide next state
*/
int state = 0;      // current state
int exitUI = 0;     // set to 1 to exit UI (and thus the program)
int maxNum;         // max number that can be picked, inclusive
char fileinput[1000];   // maxNum file input
char input[1000];   // lastest input
int option;         // int version of input
int r;              // random number

int main() {
    // seed rng for numbers
    srand(time(NULL));
    // set value of maxNum via file
    FILE *fptr = fopen("max", "r");
    // read from file
    if (fptr == NULL) {
        printf("Error opening file... creating new max file\n");
        fclose(fptr);
        fptr = fopen("max", "w");
        fprintf(fptr, "10");
        fclose(fptr);
        fptr = fopen("max", "r");
    }

    fscanf(fptr, "%s", &fileinput);
    maxNum = atoi(fileinput);

    
    while(!exitUI) {
        switch(state){
            case 0:
                printf("Number Guessing Game:\n");
                printf("Press 1 to play a game\n");
                printf("Press 2 to change the max number\n");
                printf("press 3 to quit\n");
                scanf("%s", &input);
                option = atoi(input);
                if(option > 3 || option < 0) {
                    printf("Invalid option!\n\n\n");
                    break;
                }   
                if (option == 1) {
                    // set random number for game
                    r = (rand() % maxNum) + 1;
                }

                state = option;
                break;
            case 1:
                // choose number between 1 - maxNum, inclusive
                printf("Guess a number!\n");
                scanf("%s", &input);
                if(strcmp(input, "q") == 0) {
                    state = 0;
                    break;
                }
                option = atoi(input);
                // check for entered q
                if(option == r) {
                    // correct
                    printf("You win!!\n\n\n");
                    state = 0;
                    break;
                } else if (option < r) {
                    // too low
                    printf("Too low... Try again\n");
                    break;
                } else if (option > r) {
                    // too high
                    printf("Too high... Try again\n");
                    break;
                }
            break;
            case 2:
                printf("Settings: Max Number\n");
                printf("Choose a new maximum number that can be guessed.\n");
                printf("The current max number is: %d\n", maxNum);
                scanf("%s", &input);
                option = atoi(input);
                if(option > INT_MAX || option <= 0) {
                    printf("Invalid option!\n");
                    break;
                }
                FILE *fptr;
                fptr = fopen("./max","w");
                fprintf(fptr, "%s", input);
                fclose(fptr);
                maxNum = option;
                printf("New max number: %d\n", maxNum);
                state = 0;
            break;
            case 3:
            printf("Exiting...\n");
            exitUI = 1;
            break;
        }

    }
}