#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[60];
    FILE* input = fopen("input.txt", "r");

    int max_calories = 0;
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
        max_calories = (cur_calories > max_calories) ? cur_calories : max_calories;
    }
    printf("The max calories was %d\n", max_calories);
    fclose(input);
}
