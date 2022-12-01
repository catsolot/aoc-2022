#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[60];
    FILE* input = fopen("input.txt", "r");

    int first_calories = 0;
    int second_calories = 0;
    int third_calories = 0;
    int cur_calories = 0;

    while(feof(input) == 0)
    {
        cur_calories = 0;
        fgets(buffer, 59, input);
        while (buffer[0] != '\n' && feof(input) == 0)
        {
            cur_calories += atoi(buffer);
            fgets(buffer, 59, input);
        }
        if (cur_calories > first_calories)
        {
            third_calories = second_calories;
            second_calories = first_calories;
            first_calories = cur_calories;
        }
        else if (cur_calories > second_calories)
        {
            third_calories = second_calories;
            second_calories = cur_calories;
        }
        else if (cur_calories > third_calories)
        {
            third_calories = cur_calories;
        }
    }
    printf("The sum of the top three elves calories is  %d\n", first_calories + second_calories + third_calories);
    fclose(input);
}
