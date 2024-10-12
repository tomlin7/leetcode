#include <stdio.h>

void push(int *st, int *top, int max, int item) {
    if (*top == max - 1) {
        printf("Stack Overflow while pushing %d\n", item);
        return;
    }
    st[++(*top)] = item;
    printf("Pushed %d\n", item);
}

int pop(int *st, int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return st[(*top)--];
}

void display(int *st, int top, int max) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = max - 1; i >= 0; i--)
        printf("\n[ %d ]", st[i]);

    printf("\n\n");
}

int main() {
    int st[50], top = -1, max = 5;
    push(st, &top, max, 10);
    push(st, &top, max, 20);
    push(st, &top, max, 30);
    push(st, &top, max, 40);
    push(st, &top, max, 50);
    push(st, &top, max, 60); // stack overflow
    display(st, top, max);

    printf("Popped: %d\n", pop(st, &top));
    printf("Popped: %d\n", pop(st, &top));
    display(st, top, max);

    push(st, &top, max, 150);
    push(st, &top, max, 160);
    display(st, top, max);

    return 0;
}