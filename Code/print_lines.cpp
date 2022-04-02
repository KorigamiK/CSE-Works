#include <stdio.h>
int main(int argc, char const *argv[])
{
  char x, text[100];
  int i = 0;
  while (x = getchar())
  {
    if (x == '\n')
    {
      for (int j = 0; j < i; j++)
        printf("%c\n", text[j]);
      break;
    }
    else
      text[i] = x;
    i++;
  }

  return 0;
}
