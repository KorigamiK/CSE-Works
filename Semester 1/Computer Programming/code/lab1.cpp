#include <bits/stdc++.h>

using namespace std;

#define print(x) cout << x << '\n'

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int sumNatural(int n)
{
    if (n == 0)
        return 0;
    return n + sumNatural(n - 1);
}

/* Tail Recursion */
int fib(int term, int val = 1, int prev = 0)
{
    if (term == 0)
        return prev;
    return fib(term - 1, val + prev, val);
}

void towerOfHanoi(int numberOfRings, int start, int end)
{

    if (numberOfRings == 0)
        return;

    int other = 6 - start - end;

    towerOfHanoi(numberOfRings - 1, start, other);
    printf("Move ring from %d to %d\n", start, end);
    towerOfHanoi(numberOfRings - 1, other, end);
}

int main(int argc, char const *argv[])
{
    print(factorial(5));
    print(sumNatural(5));
    print(fib(3));
    towerOfHanoi(2, 1, 3);
    return 0;
}
