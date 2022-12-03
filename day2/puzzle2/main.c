#include <stdio.h>
#include <stdlib.h>

#define ROCK 1
#define PAPER 2
#define SCIS 3
#define LOSE 0
#define DRAW 3
#define WIN 6

int calc_score(char, char);

int main()
{
    FILE* input = fopen("input.txt", "r");
    
    char me;
    char opp; 
    int total_score = 0;
    while(feof(input) == 0)
    {
        fscanf(input, "%c %c \n", &opp, &me);
        int score = calc_score(me, opp);
        printf("%d\n", score);
        total_score += score;
    }
    printf("Total score is %d\n", total_score);
    return 0;
}


int calc_score(char me, char opp)
{
    switch (opp)
    {
        case 'A':
            printf("A\n");
            switch (me)
            {
                case 'X':
                    return SCIS + LOSE;
                case 'Y':
                    return ROCK + DRAW;
                case 'Z':
                    return PAPER + WIN;
            }
            break;
        case 'B':
            printf("B\n");
            switch (me)
            {
                case 'X':
                    return ROCK + LOSE;
                case 'Y':
                    return PAPER + DRAW;
                case 'Z':
                    return SCIS + WIN;
            }
            break;
        case 'C':
            printf("C\n");
            switch (me)
            {
                case 'X':
                    return PAPER + LOSE;
                case 'Y':
                    return SCIS + DRAW;
                case 'Z':
                    return ROCK + WIN;
            }
            break;
    }
} 
