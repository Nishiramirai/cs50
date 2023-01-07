#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
void printTheWinner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //print who wins: player1, player2 or tie
    printTheWinner(score1, score2);
}

//returns a score for this word
int compute_score(string word)
{
    //Number of points, that function will return
    int points = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char currentChar = word[i];

        //If character is uppercase, make it lower
        if (currentChar >= 65 && currentChar <= 90)
        {
            points += POINTS[currentChar - 65];
        }

        else if (currentChar >= 97 && currentChar <= 122)
        {
            points += POINTS[currentChar - 97];
        }

    }
    return points;

}

//print if player 1 win, player 2, or it's a tie
void printTheWinner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
}
