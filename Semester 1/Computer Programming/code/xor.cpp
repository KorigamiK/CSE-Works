#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a, b;
  printf("Enter 2 numbers:\n");
  scanf("%d", &a);
  scanf("%d", &b);
  int xor_result = (a | b) & (~(a & b));
  printf("The XOR of %d and %d is equal to %d\n", a, b, xor_result);
  return 0;
}
