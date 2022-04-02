#include <stdio.h>

int main()
{
  int blank_char = 0, tab_char = 0, new_line = 0, c;
  printf("Number of blanks, tabs, and newlines:\n");
  printf("Input few words/tab/newlines\n");
  while ((c = getchar()) != EOF)
  {
    switch (c)
    {
    case ' ':
      ++blank_char;
      break;
    case '\t':
      ++tab_char;
      break;
    case '\n':
      ++new_line;
      break;
    default:
      break;
    }
  }
  printf("\nblank=%d, tab=%d, newline=%d\n", blank_char, tab_char, new_line);
}