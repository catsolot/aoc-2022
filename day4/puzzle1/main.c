#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* input = fopen("input.txt", "r");
    int total = 0;
    int first_low, first_high, second_low, second_high;
    while (feof(input) == 0)
    {
        fscanf(input, "%d-%d,%d-%d\n", &first_low, &first_high, &second_low, &second_high);
        if (second_low >= first_low && second_high <= first_high)
        {
            total++;
        }
        else if (first_low >= second_low && first_high <= second_high) 
        {
             total++;
        }
    }
    printf("Total %d\n", total);

}
        
