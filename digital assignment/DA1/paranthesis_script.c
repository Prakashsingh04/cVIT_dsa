#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024
typedef struct {
    int curly;
    int round;
    int angle;
} ParenCount;

int isBalanced(char *str, ParenCount *count) 
{
	int i;
    int stack[MAX];
    int top = -1;

    for ( i = 0; i < strlen(str); i++) 
	{
        char c = str[i];
        if (c == '{' || c == '(' || c == '<') 
		{
            stack[++top] = c;
            if (c == '{') 
			{
                count->curly++;
            } 
			else if (c == '(') 
			{
                count->round++;
            } 
			else 
			{
                count->angle++;
            }
        }
 
        else if (c == '}' || c == ')' || c == '>') 
		{
            if (top == -1) 
			{
             
                return 0;
            }

            char open = stack[top--];

            if ((c == '}' && open != '{') ||
                (c == ')' && open != '(') ||
                (c == '>' && open != '<')) {
                return 0;
            }
        }
    }
    return top == -1;
}

void printCount(ParenCount *count) 
{
    printf("Curly Braces: %d\n", count->curly);
    printf("Round Parentheses: %d\n", count->round);
    printf("Angle Brackets: %d\n", count->angle);

    if (count->curly < 5) 
	{
        printf("Curly Braces: Insufficient\n");
    } 
	else if (count->curly <= 10) 
	{
        printf("Curly Braces: Moderate\n");
    } 
	else 
	{
        printf("Curly Braces: Sufficient\n");
    }

    if (count->round < 5) 
	{
        printf("Round Parentheses: Insufficient\n");
    } 
	else if (count->round <= 10) 
	{
        printf("Round Parentheses: Moderate\n");
    } 
	else 
	{
        printf("Round Parentheses: Sufficient\n");
    }

    if (count->angle < 5) 
	{
        printf("Angle Brackets: Insufficient\n");
    } 
	else if (count->angle <= 10) 
	{
        printf("Angle Brackets: Moderate\n");
    } 
	else 
	{
        printf("Angle Brackets: Sufficient\n");
    }
}

int main() 
{
    char code[MAX];
    ParenCount count = {0, 0, 0};

    printf("Enter the code: ");
    fgets(code, MAX, stdin);

   
    code[strlen(code) - 1] = '\0';

    if (isBalanced(code, &count)) 
	{
        printf("Parentheses are balanced\n");
        printCount(&count);
    } 
	else 
	{
        printf("Parentheses are not balanced\n");
    }

    return 0;
}

