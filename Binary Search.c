#include <stdio.h>

int main() {
    int arr[100], n, key, low, high, mid, i, found = 0;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    printf("Enter elements (sorted): ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found at position %d\n", mid);
            found = 1;
            break;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
