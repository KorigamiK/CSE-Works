#include <stdio.h>

int main(int argc, char const *argv[])
{
  float a, b;
  printf("Enter 2 numbers:\n");
  scanf("%f", &a);
  scanf("%f", &b);
  b == 0
      ? printf("Undefined Behavior\n")
      : printf("The quotient is: %.2f\n", a / b);
  return 0;
}
