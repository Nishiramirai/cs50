#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letter(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(float letters, float words, float sentences);

int main(void)
{
    int letters;
    string text;

    //Ask user for a text, until it will have at least 1 letter
    do
    {
        //Getting User Input
        text = get_string("Text: ");

        //Calculate letters count
        letters = count_letter(text);
    }
    while (letters < 1);

    //Calculate Words count
    int words = count_words(text);

    //Calculate sentences count
    int sentences = count_sentences(text);

    //CalculateIndex
    int grade = calculate_index(letters, words, sentences);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

int count_letter(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    // before returning number of words, we need to add 1 word, because there are no space after last word
    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int calculate_index(float letters, float words, float sentences)
{
    float l = letters / words * 100; // letters per 100 words
    float s = sentences / words * 100; // sentences per 100 words

    return round(0.0588 * l - 0.296 * s - 15.8);
}