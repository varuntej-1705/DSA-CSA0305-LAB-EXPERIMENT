#include <stdio.h>
int main() {
    int n, rev = 0, rem;
    printf("Enter a 32-bit signed integer: ");
    scanf("%d", &n);

    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    printf("Reversed Number = %d\n", rev);
    return 0;
}
