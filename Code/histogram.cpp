#include <stdio.h>
#include <string.h>
void histogram(const int offset, const int range)
{
  int histogram[range];
  memset(histogram, 0, sizeof(histogram)); // initialize 95 spaces for ASCII characters 32 - 127

  int special = 0;

  int c;
  while ((c = getchar()) != EOF)
  {
    if (c < offset || c >= (offset + range))
      special++;
    else
      ++histogram[c - offset];
  }

  for (int i = 0; i < range; ++i)
  {
    c = i + offset;
    printf("%c ", c);
    for (int j = 0; j < histogram[i]; ++j)
      putchar('x');
    putchar('\n');
  }

  printf("- ");
  for (int j = 0; j < special; j++)
    putchar('x');
  putchar('\n');
}

int main(void)
{
  histogram(' ', 95); // ' ' is 32 in ascii
}