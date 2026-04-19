#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000000

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

bool isMatch(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char *s)
{
    top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty())
                return false;

            char top_char = pop();

            if (!isMatch(top_char, ch))
                return false;
        }
    }

    return isEmpty();
}

int main()
{
    char *tests[] = {"[{()}]", "[()(){}", "([)", "[{()})"};
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        printf("Input:  \"%s\"\n", tests[i]);
        printf("Output: %s\n\n", isBalanced(tests[i]) ? "true" : "false");
    }

    return 0;
}