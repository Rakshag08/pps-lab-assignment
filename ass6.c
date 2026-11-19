#include <stdio.h>

/* Without recursion */
long factIterative(int n) {
    long f = 1;
    int i;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}

/* With recursion */
long factRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factRecursive(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers\n");
        return 0;
    }

    printf("Factorial of number (without recursion) = %ld\n", factIterative(n));
    printf("Factorial of number (with recursion)    = %ld\n", factRecursive(n));
    return 0;
}
