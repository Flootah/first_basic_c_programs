#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Restaurant Bill:
- Prompt user for two floats, used for tax and tip percentages
- use rng to determine which of 4 meal costs to use
- use simple arithmetic to calculate tip, tax, and total
- print to screen
*/

float meals[4] = {9.95, 4.55, 13.25, 22.35};                    // prices of the 4 meals
char mealnames[4][10] = {"Salad", "Soup", "Sandwich", "Pizza"}; // names of the 4 meals
float taxPercentage = 0;                                        // tax percentage
float tipPercentage = 0;                                        // tip percentage

int main() {
    // prompt for percentages
    printf("Restaurant Bill Calculator:\n\n");
    printf("Enter tax amount as percentage: ");
    scanf("%f", &taxPercentage);
    printf("Enter tip amount as percentage: ");
    scanf("%f", &tipPercentage);

    // create rng for meal
    srand(time(NULL));
    int r = rand() % 4;
    // set meal price and determine tax, tip, and total
    float meal = meals[r];
    float tax = meal * taxPercentage * 0.01;
    float tip = meal * tipPercentage * 0.01;
    float total = meal + tax + tip;
    printf("%10s", mealnames[r]); printf(":"); printf("%6.2f\n", meal);
    printf("%10s", "Tax:"); printf("%6.2f\n", tax);
    printf("%10s", "Tip:"); printf("%6.2f\n", tip);
    printf("%10s", "Total:"); printf("%6.2f\n", total);
}