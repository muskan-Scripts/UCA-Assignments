#include <stdio.h>
#include <stdbool.h>
#include<assert.h>
#include<string.h>

struct Stack
{
    int top;
    char arr[10000];
};

bool isFull(struct Stack *mystack, int size)
{
    return mystack->top == size - 1;
}
bool isEmpty(struct Stack *mystack)
{
    return mystack->top == -1;
}
void push(char ele, struct Stack *mystack, int size)
{
    if (isFull(mystack, size))
    {
        return;
    }
    mystack->arr[++mystack->top] = ele;
}

void pop(struct Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return;
    }
    mystack->top--;
}
char top(struct Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return '0';
    }
    return mystack->arr[mystack->top];
}
bool isValid(char *s)
{
    struct Stack myStack;
    myStack.top = -1;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i], &myStack, n);
        }
        else
        {
            if (isEmpty(&myStack))
            {
                return false;
            }
            else
            {
                char topEle = top(&myStack);
                if ((topEle == '{' && s[i] == '}') ||
                    (topEle == '(' && s[i] == ')') ||
                    (topEle == '[' && s[i] == ']'))
                {
                    pop(&myStack);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (isEmpty(&myStack))
    {
        return true;
    }
    return false;
}

int main()
{
    char myString[100];  // Assuming a string of maximum length 99 characters

    printf("Enter a string: ");
    scanf("%s", myString);
    assert(isValid(myString)==false);

    return 0;
}