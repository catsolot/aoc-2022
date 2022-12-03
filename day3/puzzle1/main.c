#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char find_match(char* first, char* second);
int priority(char item);

int main()
{
    char* string;
    char* copy;
    int length = 0;
    int total = 0;
    FILE* input = fopen("input.txt", "r");
    while (feof(input) == 0)
    {
        string = calloc(sizeof(char), 100);
        copy = calloc(sizeof(char), 100);
        fscanf(input, "%s\n", string);
        length = strlen(string);
        strcpy(copy, string);
        // aaaaaa
        *(string + (length / 2)) = '\0';
        copy = copy + (length / 2);
        char match = find_match(string, copy);
        total += priority(match);
        printf("%s %s  %c\n", string, copy, match);
        free(string);
        free(copy - (length / 2));
    }
    printf("Final score is %d\n", total);
    fclose(input);
}

char find_match(char* first, char* second)
{
    int index;
    while (*first != '\0')
    {
        index = 0;
        while (*(second + index) != '\0')
        {
            if (*first == *(second + index))
            {
                return *first;
            }
            index++;
        }
        first += 1;
    }
    return '\0';
}

int priority(char item)
{
    int val;
    if (islower(item))
    {
       val = item - 'a' + 1; 
    }
    else
    {
        val = item - 'A' + 27;
    }
    return val;
}

