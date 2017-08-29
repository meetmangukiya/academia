/**
 * Program to evaluate an infix expression by converting infix to postfix
 * and then evalating the postfix expression.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define SIZE 100

struct Stack {
    char data[SIZE];
    int top;
};

struct Stack createStack() {
    struct Stack stack;
    stack.top = -1;
    return stack;
}

void push(char data, struct Stack* stack) {
    if (stack->top != SIZE - 1) {
        stack->data[++stack->top] = data;
    }
    else {
        printf("ERROR! Stack overflow");
    }
}

char pop(struct Stack* stack) {
    if (stack->top != -1) {
        return stack->data[stack->top--];
    }
    else {
        printf("ERROR! Stack underflow");
    }
}

char peek(struct Stack stack) {
    if (stack.top != -1) {
        return stack.data[stack.top];
    }
    else {
        printf("Empty stack.");
    }
}

char* infix_to_postfix(char* string, char* res) {
    int i;
    struct Stack stack = createStack();
    push('(', &stack);
    strcat(string, ")");

    for(i = 0; i < strlen(string); i++) {
        if (isdigit(string[i])) {
            res[strlen(res)] = string[i];
        }
        else {
            if (string[i] == '(') {
                push('(', &stack);
            }
            else if (string[i] == ')') {
                while(peek(stack) != '(') {
                    res[strlen(res)] = pop(&stack);
                }
                pop(&stack);
            }
            else {
                if(string[i] == '+' || string[i] == '-') {
                    while(peek(stack) != '(' && stack.top != -1) {
                        res[strlen(res)] = pop(&stack);
                    }
                    push(string[i], &stack);
                }
                else {
                    if ((peek(stack) == '/' || peek(stack) == '*') &&
                         stack.top != -1) {
                        while(peek(stack) != '(' && stack.top != -1) {
                            res[strlen(res)] = pop(&stack);
                        }
                    }
                    push(string[i], &stack);
                }
            }
        }
    }
    while(stack.top != -1) {
        res[strlen(res)] = pop(&stack);
    }
    return res;
}

struct FloatStack {
    float data[SIZE];
    int top;
};

struct FloatStack createFloatStack() {
    struct FloatStack stack;
    stack.top = -1;
    return stack;
}

void push_float(float data, struct FloatStack* stack) {
    if (stack->top != SIZE - 1) {
        stack->data[++stack->top] = data;
    }
    else {
        printf("ERROR! Stack overflow");
    }
}

float pop_float(struct FloatStack* stack) {
    if (stack->top != -1) {
        return stack->data[stack->top--];
    }
    else {
        printf("ERROR! Stack underflow");
    }
}

float evaluate_postfix(char* string) {
    struct FloatStack stack = createFloatStack();
    int i;
    for(i = 0; i < strlen(string); i++) {
        if (isdigit(string[i])) {
            push_float((int)string[i] - 48, &stack);
        }
        else {
            int op2 = pop_float(&stack);
            int op1 = pop_float(&stack);
            int res;
            switch(string[i]) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }
            push_float(res, &stack);
        }
    }
    return pop_float(&stack);
}

int main() {
    char res[100] = "";
    char expression[100];

    clrscr();
    printf("Expression: ");
    gets(expression);

    printf("Postfix: %s\n", infix_to_postfix(expression, res));
    printf("Result: %f", evaluate_postfix(res));
    getch();
}
