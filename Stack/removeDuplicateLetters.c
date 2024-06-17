#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 26

typedef struct {
    int* elements;
    int top;
} MyStack;

MyStack* createMyStack() {
    MyStack* myStack = (MyStack*)malloc(sizeof(MyStack));
    myStack->elements = (int*)malloc(MAX_STACK_SIZE * sizeof(int));
    myStack->top = -1;
    return myStack;
}

void pushToMyStack(MyStack* myStack, int value) {
    myStack->elements[++myStack->top] = value;
}

int popFromMyStack(MyStack* myStack) {
    return myStack->elements[myStack->top--];
}

bool isMyStackEmpty(MyStack* myStack) {
    return myStack->top == -1;
}

char* modifyString(char* inputString) {
    MyStack* stack = createMyStack();
    int lastIndices[MAX_STACK_SIZE] = {0};
    bool seen[MAX_STACK_SIZE] = {false};

    // Store last index of each character of string in lastIndices array
    for (int i = 0; i < strlen(inputString); i++) {
        lastIndices[inputString[i] - 'a'] = i;
    }

    for (int i = 0; i < strlen(inputString); i++) {
        int current = inputString[i] - 'a';

        if (seen[current]) {
            continue;
        }

        while (!isMyStackEmpty(stack) && stack->elements[stack->top] > current && i < lastIndices[stack->elements[stack->top]]) {
            seen[popFromMyStack(stack)] = false;
        }

        pushToMyStack(stack, current);
        seen[current] = true;
    }

    char* resultString = (char*)malloc((stack->top + 2) * sizeof(char));
    int index = 0;

    while (!isMyStackEmpty(stack)) {
        resultString[index++] = popFromMyStack(stack) + 'a';
    }

    resultString[index] = '\0';

    // Reverse the string
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = resultString[start];
        resultString[start] = resultString[end];
        resultString[end] = temp;
        start++;
        end--;
    }

    return resultString;
}

int main() {
    char userInput[100];

    printf("Enter a string: ");
    scanf("%s", userInput);

    char* modifiedResult = modifyString(userInput);

    printf("Modified string: %s\n", modifiedResult);

    free(modifiedResult); // Don't forget to free the allocated memory

    return 0;
}
