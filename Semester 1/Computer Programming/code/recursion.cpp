#include <stdio.h>

int evenFunc(int n);

int main()
{
  evenFunc(20);
  printf("This is hello from nvim");
  return 0;
}

int evenFunc(int n)
{
  if (n == 0)
    return 0;
  evenFunc(n - 1);
  if ((n % 2) == 0)
    return 0;
  return 1;
}
