#include <stdio.h>
#define SIZE 100

int q1[SIZE], q2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

int isEmpty1() { return front1 == -1; }
int isEmpty2() { return front2 == -1; }

void enqueue1(int x) {
    if (rear1 == SIZE-1) return;
    if (front1 == -1) front1 = 0;
    q1[++rear1] = x;
}
int dequeue1() {
    if (isEmpty1()) return -1;
    int x = q1[front1];
    if (front1 == rear1) front1 = rear1 = -1;
    else front1++;
    return x;
}
void enqueue2(int x) {
    if (rear2 == SIZE-1) return;
    if (front2 == -1) front2 = 0;
    q2[++rear2] = x;
}
int dequeue2() {
    if (isEmpty2()) return -1;
    int x = q2[front2];
    if (front2 == rear2) front2 = rear2 = -1;
    else front2++;
    return x;
}

void push(int x) {
    enqueue2(x);
    while (!isEmpty1()) enqueue2(dequeue1());
    while (!isEmpty2()) enqueue1(dequeue2());
}

int pop() {
    if (isEmpty1()) return -1;
    return dequeue1();
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Popped: %d\n", pop());
    printf("Popped: %d\n", pop());
    return 0;
}
