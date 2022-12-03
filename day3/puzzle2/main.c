#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char find_match(char* first, char* second, char* third);
int priority(char item);

int main()
{
    char* string1;
    char* string2;
    char* string3;
    int length = 0;
    int total = 0;
    FILE* input = fopen("input.txt", "r");
    while (feof(input) == 0)
    {
        string1 = calloc(sizeof(char), 100);
        string2 = calloc(sizeof(char), 100);
        string3 = calloc(sizeof(char), 100);
        fscanf(input, "%s\n%s\n%s\n", string1, string2, string3);
        //length = strlen(string);
        //strcpy(copy, string);
        // aaaaaa
        //*(string + (length / 2)) = '\0';
        //copy = copy + (length / 2);
        char match = find_match(string1, string2, string3);
        total += priority(match);
        free(string1);
        free(string2);
        free(string3);
    }
    printf("Final score is %d\n", total);
    fclose(input);
}

char find_match(char* first, char* second, char* third)
{
    int index;
    int index2;
    while (*first != '\0')
    {
        index = 0;
        while (*(second + index) != '\0')
        {
            index2 = 0;
            while (*(third + index2) != '\0')
            {
                if (*first == *(second + index) &&
                    *first == *(third  + index2))
                {
                return *first;
                }
                index2++;
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

