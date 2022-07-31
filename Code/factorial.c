#include <stdio.h>
typedef unsigned long long ull;

ull factorial(ull i)
{
    if (i == 0)
        return 1;
    return factorial(i - 1) * i;
}
int main(int argc, char const *argv[])
{

    int n;
    ull fact = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // shows error if the user enters a negative integer
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else
        fact = factorial(n);
    printf("Factorial of %d = %llu", n, fact);

    return 0;
}
