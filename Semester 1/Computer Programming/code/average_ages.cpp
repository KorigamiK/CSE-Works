#include <stdio.h>
#include <stdlib.h>

float avg(int arr[], int n)
{
  float sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  return sum / (float)n;
}

int main(int argc, char const *argv[])
{
  int n;
  printf("Enter number of employees: ");
  scanf("%d", &n);

  int *employees = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    printf("Enter age of employee %d: ", i + 1);
    scanf("%d", &employees[i]);
  }

  printf("The average age of employees is = %.2f\n", avg(employees, n));

  free(employees);

  return 0;
}
