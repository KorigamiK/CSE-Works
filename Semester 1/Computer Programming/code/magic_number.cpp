#include <stdio.h>

bool is_magic(int num)
{
  int sum_of_digits = 0, reversed = 0, original = num;
  while (num)
  {
    sum_of_digits += num % 10;
    reversed = reversed * 10 + (num % 10);
    num /= 10;
  }
  return sum_of_digits * reversed == original;
}

int main(int argc, char const *argv[])
{
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  is_magic(number)
      ? printf("It is a Magic Number!\n")
      : printf("Not a Magic number :(\n");

  return 0;
}
