#include <stdio.h>
int main() {
    int n, a = 0, b = 1, c, sum = 1, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n == 1) sum = 0;
    else if (n == 2) sum = 1;
    else {
        for (i = 3; i <= n; i++) {
            c = a + b;
            sum += c;
            a = b;
            b = c;
        }
    }

    printf("Sum of Fibonacci series = %d\n", sum);
    return 0;
}
