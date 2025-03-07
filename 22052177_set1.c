// WAP to convert an infix expression to postfix expression using stack.
// a+b*(c^d-e)^(f+g*h)-i
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

struct Stack {
    int top;
    char items[size];
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char item) {
    if (stack->top == size - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack) {
    return stack->items[stack->top];
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    initStack(stack);
    int i, j;
    char ch;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(ch) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
    }
    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[size], postfix[size];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

// Enter an infix expression: a+b*(c^d-e)^(f+g*h)-i
// Postfix expression: abcd^e-fgh*+^*+i-