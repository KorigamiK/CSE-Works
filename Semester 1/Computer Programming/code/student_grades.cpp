#include <stdio.h>

struct student
{
  char grade;
};

void get_marks(student classes[][30])
{
  int m, n;

  printf("\nEnter class: ");
  scanf("%d", &m);
  printf("Enter student: ");
  scanf("%d", &n);

  printf("The given student has got %c grade!\n", classes[m - 1][n - 1]);
}

void populate_classes(student classes[3][30])
{
  int num;

  for (int i = 0; i < 3; i++)
  {
    student *curr_class = classes[i];
    printf("Enter number of students in class %d: ", i + 1);
    scanf("%d", &num);

    for (int j = 0; j < num; j++)
    {
      printf("Enter the Grade of student %d in class %d: ", j + 1, i + 1);
      scanf(" %c", &(curr_class[j].grade)); // blank space is important
    }
    printf("\n");
  }
}

int main(int argc, char const *argv[])
{

  student classes[3][30];

  populate_classes(classes);
  get_marks(classes);

  return 0;
}
