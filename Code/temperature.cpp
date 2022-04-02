#include <stdio.h>

double to_celcius(int fahr)
{
  return (fahr - 32) * (5.0 / 9.0);
}

int main()
{
  int fahr;
  printf("Fahrenheit     \t Celcius\n");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20)
    printf("%3d \t\t %6.1f\n", fahr, to_celcius(fahr));
}