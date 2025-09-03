#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void kthMin(struct Node* root, int k, int* count, int* result) {
    if (!root) return;
    kthMin(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    kthMin(root->right, k, count, result);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int k, count = 0, result = -1;
    printf("Enter k: ");
    scanf("%d", &k);
    kthMin(root, k, &count, &result);
    if (result != -1) printf("%d-th minimum value = %d\n", k, result);
    else printf("Less than %d nodes in tree\n", k);
    return 0;
}
