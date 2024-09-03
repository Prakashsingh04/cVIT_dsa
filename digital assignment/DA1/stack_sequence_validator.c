#include <stdio.h>
int validate(int* push, int n, int* pop, int m) //n=push size m=popped size 
{
    int stk[20];
    int top = -1;
    int i = 0, j = 0;

    while (j < m) 
    {
        if (top == -1 || stk[top] != pop[j]) 
        {
            if (i < n) 
            {
                stk[++top] = push[i++];
            } 
            else 
            {
                return 0; 
            }
        } 
        else 
        {
            printf("\nPopped element is %d", stk[top--]);
            j++;
        }
    }
    return 1;
}

int main() 
{
    int n, m, i;
    printf("Enter the size of pushed array: ");
    scanf("%d", &n);
    int push[n];
    printf("Enter the pushed array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &push[i]);
    }

    printf("Enter the size of popped array: ");
    scanf("%d", &m);
    int pop[m];
    printf("Enter the popped array: ");
    for (i = 0; i < m; i++) 
    {
        scanf("%d", &pop[i]);
    }

    if (validate(push, n, pop, m)) 
    {
        printf("\nOutput: 1\n");
    } 
    else 
    {
        printf("\nOutput: 0\n");
    }
    return 0;
}

