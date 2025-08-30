#include <stdio.h>

int main() {
    int arr[100], n = 0, choice, pos, val, i;

    while (1) {
        printf("\n--- Array Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                if (pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = n; i > pos; i--)
                        arr[i] = arr[i - 1];
                    arr[pos] = val;
                    n++;
                }
                break;
            case 2: // Delete
                printf("Enter position: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position!\n");
                } else {
                    for (i = pos; i < n - 1; i++)
                        arr[i] = arr[i + 1];
                    n--;
                }
                break;
            case 3: // Display
                printf("Array: ");
                for (i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
