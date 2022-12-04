#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* input = fopen("input.txt", "r");
    int total = 0;
    int flag = 1;
    int first_low, first_high, second_low, second_high;
    while (feof(input) == 0)
    {
        fscanf(input, "%d-%d,%d-%d\n", &first_low, &first_high, &second_low, &second_high);
        for (int i = first_low; i <= first_high; i++)
        {
            if (i <= second_high && i >= second_low)
            {
                total++;
                break;
            }
        }
    }
    printf("Total %d\n", total);
}
        
