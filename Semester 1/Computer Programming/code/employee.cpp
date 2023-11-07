#include <stdio.h>

struct address
{
  int street;
  char city[50];
  char district[50];
  char state[50];
};

struct employee
{
  char Emp_Name[50];
  int Emp_Age;
  char Emp_Degree[50];
  float Emp_Exp;
  address Emp_add;
};

void add_emploee(employee &Employee, int i)
{
  printf("\nEnter Name of employee %d: ", i);
  scanf("%s", &Employee.Emp_Name);
  printf("Enter Age of employee %d: ", i);
  scanf("%d", &Employee.Emp_Age);
  printf("Enter Degree of employee %d: ", i);
  scanf("%s", &Employee.Emp_Degree);
  printf("Enter Experience of employee %d: ", i);
  scanf("%f", &Employee.Emp_Exp);

  printf("*Address Details*\n");
  printf("Enter City of employee %d: ", i);
  scanf("%s", &Employee.Emp_add.city);
  printf("Enter District of employee %d: ", i);
  scanf("%s", &Employee.Emp_add.district);
  printf("Enter State of employee %d: ", i);
  scanf("%s", &Employee.Emp_add.state);
  printf("Enter Street of employee %d: ", i);
  scanf("%d", &Employee.Emp_add.street);
}

void print_employee(employee Employee)
{
  printf("\n%s %s %s", Employee.Emp_Name, Employee.Emp_Degree, Employee.Emp_add.city);
}

int main(int argc, char const *argv[])
{
  int n;
  printf("Enter Number of employees: ");
  scanf("%d", &n);

  employee Employees[n];

  for (int i = 0; i < n; i++)
    add_emploee(Employees[i], i + 1);

  for (int i = 0; i < n; i++)
    print_employee(Employees[i]);
  return 0;
}
