#include <stdio.h>
int main(int argc, char const *argv[])
{

    int arr[10], Size, i, Search, Flag;
    printf("\n Please Enter the size of an array : ");
    scanf("%d", &Size);
    printf("\n Please Enter %d elements of an array: \n", Size);
    for (i = 0; i < Size; i++)
        scanf("%d", &arr[i]);
    printf("\n Please Enter the Search Element : ");
    scanf("%d", &Search);
    Flag = 0;
    for (i = 0; i < Size; i++)
        if (arr[i] == Search)
        {
            Flag = 1;
            break;
        }
    if (Flag == 1)
        printf("\n We found the Search Element %d at Position %d ", Search, i + 1);
    else
        printf("\n Sorry!! We haven't found the the Search Element %d ", Search);
    return 0;
}
