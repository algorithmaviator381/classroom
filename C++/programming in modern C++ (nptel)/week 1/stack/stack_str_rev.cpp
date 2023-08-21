#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %c.\n", c);
    } else {
        s->top++;
        s->items[s->top] = c;
    }
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    } else {
        char c = s->items[s->top];
        s->top--;
        return c;
    }
}

void reverseStringUsingStack(char *input) {
    struct Stack stack;
    initialize(&stack);

    // Push each character onto the stack
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    // Pop characters from the stack to reverse the string
    for (int i = 0; i < strlen(input); i++) {
        input[i] = pop(&stack);
    }
}

int main() {
    char input[] = "381";
    printf("Original: %s\n", input);

    reverseStringUsingStack(input);
    printf("Reversed: %s\n", input);

    return 0;
}
