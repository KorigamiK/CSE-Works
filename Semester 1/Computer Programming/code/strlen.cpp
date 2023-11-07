#include <stdio.h>
int main()
{
  char str[100], i;
  printf("Enter a string: ");
  scanf("%[^\n]s", str);

  // '\0' represents end of String
  for (i = 0; str[i] != '\0'; ++i)
    ;
  printf("\nLength of input string: %d\n", i);

  return 0;
}