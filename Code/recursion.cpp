#include <stdio.h>

int evenFunc(int n);

int main()
{
  evenFunc(20);
  return 0;
}

int evenFunc(int n)
{
  if (n == 0)
    return 0;
  evenFunc(n - 1);
  if ((n % 2) == 0)
    printf("%d\n", n);
  return 0;
}