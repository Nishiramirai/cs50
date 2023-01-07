#include <cs50.h>
#include <stdio.h>

int get_population_size(int min_size, string message);
int calculate_years(int current_population, int final_population);


int main(void)
{
    // Prompt for start size
    int start_size = get_population_size(9, "Start size");

    // Prompt for end size
    int end_size = get_population_size(start_size, "End size");

    // Calculate number of years until we reach threshold
    int years = calculate_years(start_size, end_size);

    // Print number of years
    printf("Years: %i\n", years);

}


// Prompt for population size until user enter correct value
int get_population_size(int min_size, string message)
{
    int size;
    do
    {
        size = get_int("%s: ", message);
    }
    while (size < min_size);

    return size;
}


// Calculate number of years until we reach threshold
int calculate_years(int current_population, int final_population)
{
    int years = 0;

    while (current_population < final_population)
    {
        int llamas_dead = current_population / 4;
        int llamas_born = current_population / 3;

        current_population += llamas_born - llamas_dead;
        years++;
    }

    return years;
}
