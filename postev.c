/* 
Design, Develop and Implement a Program in C for the following Stack Applications 
Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^ 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50

int stack[MAX];
char post[MAX];
int top = -1;

/*FUNCTION PROTOYPE */
void pushstack(int tmp);
void calculator(char c);

int main()
{
    printf("Insert a postfix notation: ");
    scanf("%s", post);
    for (int i = 0; i < strlen(post); i++)
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            pushstack(i);
        }
        if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '%' || post[i] == '^')
        {
            calculator(post[i]);
        }
    }
    printf("\nResult is %d\n", stack[top]);
}

void pushstack(int tmp)
{
    stack[++top] = (int)(post[tmp] - 48);
}

void calculator(char c)
{
    int a, b, ans;
    a = stack[top--];
    b = stack[top--];

    switch (c)
    {
        case '+':   ans = b + a;
            break;
        case '-':   ans = b - a;
            break;
        case '*':   ans = b * a;
            break;
        case '/':   ans = b / a;
            break;          break;
        case '^':   ans = pow(b, a);
            break;
        case '%':   ans = b%a;

        default: ans = 0;
    }
    stack[++top] = ans;
}