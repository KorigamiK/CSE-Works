#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[50], n;
    printf("Enter the size of the arr:\n");
    scanf("%d", &n);
    printf("enter the elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Your array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("your sorted array here: \n");
    int i, j, a;
    for (i = 0; i < n; ++i)
        for (j = i + 1; j < n; ++j)
            if (arr[i] > arr[j])
            {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
    printf("Your array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        sum += a;
    }
    int mean = sum / n;
    int median = arr[n / 2];

    printf("\n");
    printf("your mean is given as: %d\n", mean);
    printf("your median is given as: %d\n", median);
}