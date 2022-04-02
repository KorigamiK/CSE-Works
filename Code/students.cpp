#include <stdio.h>

void print_names(char students[][20], int n)
{
  printf("\nStudents are: \n");
  for (int i = 0; i < n; i++)
    printf("%s\n", *(students + i));
}

int main(int argc, char const *argv[])
{
  int n;
  char students[50][20];
  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter the name for student %d: ", i + 1);
    scanf("%s", *(students + i));
  }
  print_names(students, n);
  return 0;
}
