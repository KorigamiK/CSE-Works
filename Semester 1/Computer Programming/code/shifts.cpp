#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a;
  printf("Enter a numbers: ");
  scanf("%d", &a);

  for (int i = 0; i < 4; i++)
    printf("%d Right shifted %d times is equal to %d\n", a, i, a >> i);
  printf("\n");
  for (int i = 0; i < 4; i++)
    printf("%d Left shifted %d times is equal to %d\n", a, i, a << i);

  return 0;
}
