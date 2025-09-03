#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse linked list
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;    // Store next node
        curr->next = prev;    // Reverse link
        prev = curr;          // Move prev forward
        curr = next;          // Move curr forward
    }
    return prev; // New head
}

int main() {
    // Creating linked list: 10 -> 20 -> 30 -> 40
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original List:\n");
    printList(head);

    head = reverse(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
