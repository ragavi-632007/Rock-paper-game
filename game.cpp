#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    

int main() {
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0, round = 1;
    srand(time(0));

    printf("Welcome to Rock, Paper, Scissors - Best of 3 Rounds!\n");

    while (round <= 3) {
        // Display choices
        printf("\nRound %d\n", round);
        printf("Choose one of the following:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Enter your choice (1, 2, or 3): ");
        scanf("%d", &userChoice);

        if (userChoice < 1 || userChoice > 3) {
            printf("Invalid choice! Please choose between 1 and 3.\n");
            continue;  
        }

        computerChoice = rand() % 3 + 1;

        const char *choices[] = {"Rock", "Paper", "Scissors"};
        printf("You chose: %s\n", choices[userChoice - 1]);
        printf("Computer chose: %s\n", choices[computerChoice - 1]);

        if (userChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if ((userChoice == 1 && computerChoice == 3) ||  // Rock beats Scissors
                   (userChoice == 2 && computerChoice == 1) ||  // Paper beats Rock
                   (userChoice == 3 && computerChoice == 2)) {  // Scissors beats Paper
            printf("You win this round!\n");
            userScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }

        round++;
    }

    // Display the final result after 3 rounds
    printf("\nFinal Score: You %d - %d Computer\n", userScore, computerScore);
    if (userScore > computerScore) {
        printf("Congratulations! You won the best of 3 rounds!\n");
    } else if (userScore < computerScore) {
        printf("Computer wins the best of 3 rounds!\n");
    } else {
        printf("It's a tie overall!\n");
    }

    return 0;
}