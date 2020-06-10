#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Pythagorean formula using command line arguments.

int main(int argc, string argv[])
{
    // we only want 2 numbers entered as cmd line arguments.
    // If there is more show user a usage error.
    if (argc != 3)
    {
        printf("Usage error: ./pythag Leg A Leg B\n");
        return 1;
    }
    // Variables had to be declared here to avoid segmentation fault.

    float leg_a = atof(argv[1]);
    float leg_b = atof(argv[2]);
    int digits_a = strlen(argv[1]);
    int digits_b = strlen(argv[2]);

    // Check if cmd line arguments are numbers.
    // If not show user usage error.
    for (int i = 0; i < digits_a; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage error: Only input numbers\n");
            return 2;
        }
    }

    for (int i = 0; i < digits_b; i++)
    {
        if (isalpha(argv[2][i]))
        {
            printf("Usage error: Only input numbers\n");
            return 2;
        }
    }

    // Implement pythagoreans formula to find hypotenuse.
    float hypo_sq = pow(leg_a, 2) + pow(leg_b, 2);
    float hypo = sqrt(hypo_sq);

    // Print hypotenuse value.

    printf("The hypotenuse is %0.2f\n", hypo);
    return 0;

}