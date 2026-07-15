//array sameas selection
//find num of swifts

#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[15] = {29,10,14,37,13,7,25,18,3,40,21,6,31,12,2};
    int i,j,key,shift;
    int n = 15;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i;
        while (j > 0 && arr[j-1] > key)
        {
            arr[j] = arr[j-1];
            j = j - 1;
            shift = shift + 1;
        }
        arr[j] = key;
    }
    printf("Sorted Array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nShifts are: %d",shift);
}