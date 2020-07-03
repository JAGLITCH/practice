#include <stdio.h>
#include <cs50.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(void)
{
    // Function prototypes.
    bool is_tie(string human_hand, string cmp_hand);
    bool valid_hand(string human_hand);
    bool score(string human_hand, string cmp_hand);
    bool winner(int human_score, int cmp_score, int num_rounds);
    void print_score(int human_score, int cmp_score, int track_rounds, int num_rounds, string name);
    void print_winner(int human_score, int cmp_score, string name);

    // Variables.
    string cmp_hand;
    int human_score = 0;
    int cmp_score = 0;
    int num_rounds;
    int track_rounds = 0;


    // Game setup.
    // Store humans name.
    // Store number of rounds for game.
    printf("\n\nROCK! PAPER! SCISSORS!\n  ()    []      8<\n");
    string name = get_string("ENTER NAME: ");

    do
    {
        int rounds = get_int("HOW MANY ROUNDS 3, 5, 7, or 9?: ");

        num_rounds = rounds;
    }
    while (num_rounds % 2 == 0 || num_rounds > 9 || num_rounds < 3);



    // Main loop
    // Loop until there is a winner.
    do
    {
        // Get human choices.
        string human_hand = get_string("SHOOT: ");

        // Generate Random Hand for Computer.
        // First generate random int using clock.
        // Assign a hand to ints to get a random choice.
        srand(time(0));
        int roll = rand() % 10 + 1;

        if (roll <= 3)
        {
            cmp_hand = "ROCK";
        }
        else if (roll <= 6)
        {
            cmp_hand = "PAPER";
        }
        else
        {
            cmp_hand = "SCISSORS";
        }

        // Check if hand is valid.
        // If valid, display choices and scores.
        if (valid_hand(human_hand))
        {
            printf("\n\n%s chooses %s\n", name, human_hand);
            printf("And COMPUTER chooses %s\n\n", cmp_hand);
        }
        else
        {
            printf("THAT'S NOT AN OPTION.\n\n");
        }


        // check if hands are the same.
        // If its a draw display its a tie and redo the round.
        if (is_tie(human_hand, cmp_hand))
        {
            printf("ITS A TIE!\n");
            print_score(human_score, cmp_score, track_rounds, num_rounds, name);
        }
        // If its not a tie check who wins the point and increment accordingly.
        else if (score(human_hand, cmp_hand))
        {
            human_score++;
            track_rounds++;
            print_score(human_score, cmp_score, track_rounds, num_rounds, name);
        }
        else if (score(human_hand, cmp_hand) == false)
        {
            if (valid_hand(human_hand))
            {
                cmp_score++;
                track_rounds++;
                print_score(human_score, cmp_score, track_rounds, num_rounds, name);
            }
        }


    }
    // Exit main loop when a winner is present.
    // Display winner.
    while (winner(human_score, cmp_score, num_rounds) == false);

    print_winner(human_score, cmp_score, name);
}


//FUNCTIONS

// Check to see if hand is valid.
bool valid_hand(string human_hand)
{
    // Covert humans choice to capitals to facilitate comparisons.
    // Only accept rock, paper, or scissors.
    // If hand is invalid do not increment rounds or scores.
    int n = strlen(human_hand);

    for (int i = 0; i < n; i++)
    {
        human_hand[i] = toupper(human_hand[i]);
    }

    if (strcmp(human_hand, "ROCK") == 0)
    {
        return true;
    }
    else if (strcmp(human_hand, "PAPER") == 0)
    {
        return true;
    }
    else if (strcmp(human_hand, "SCISSORS") == 0)
    {
        return true;
    }
    return false;
}


// Check for tie.
// If its a tie do not increment points or the current round.
bool is_tie(string human_hand, string cmp_hand)
{
    if (strcmp(human_hand, cmp_hand) == 0)
    {

        return true;
    }
    return false;
}

// Check if there is a winner.
// Winner is present after securing half of the avalible points.
// Avalible points is represented by the number of rounds.
bool winner(int human_score, int cmp_score, int num_rounds)
{
    if (human_score > num_rounds / 2 || cmp_score > num_rounds / 2)
    {
        return true;
    }
    return false;
}

// Check which hand wins and update score.
// True incrments humans score.
// False increments computer score.
bool score(string human_hand, string cmp_hand)
{
    if (strcmp(human_hand, "ROCK") == 0)
    {
        if (strcmp(cmp_hand, "SCISSORS") == 0)
        {
            return true;
        }
    }

    if (strcmp(human_hand, "PAPER") == 0)
    {
        if (strcmp(cmp_hand, "ROCK") == 0)
        {
            return true;
        }

    }

    if (strcmp(human_hand, "SCISSORS") == 0)
    {
        if (strcmp(cmp_hand, "PAPER") == 0)
        {
            return true;
        }
    }
    return false;
}


// Print score and round number.
void print_score(int human_score, int cmp_score, int track_rounds, int num_rounds, string name)
{
    printf("%s's SCORE:%i    COMPUTER SCORE:%i    ROUND:%i/%i\n", name, human_score, cmp_score, track_rounds, num_rounds);
}


// Print Winner.
// Highest score wins after a winner is present.
void print_winner(int human_score, int cmp_score, string name)
{
    if (human_score > cmp_score)
    {
        printf("%s WINS!\n", name);
    }
    else
    {
        printf("COMPUTER WINS!\n");
    }
}
