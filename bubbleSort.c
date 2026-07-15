#include<stdio.h>
#include<conio.h>
void main()
{
    int arr[15] = {14,3,19,7,2,11,6,18,1,10,5,15,9,4,13};
    int i,j,k,temp,swap = 0,pass=0,swap5=0;
    int n = 15;
    
    for(i = 0; i < n-1; i++)
    {
        pass++;
        for (j = 0; j < n; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = swap + 1;
                swap5++;
            }
        }
        if(pass == 4)
        {
            printf("Array after 4th pass: ");
            for(k = 0; k < n; k++)
            {
                printf("%d ",arr[k]);
            }
        }
        if(pass == 7)
        {
            printf("\nArray after 7th pass: ");
            for(k = 0; k < n; k++)
            {
                printf("%d ",arr[k]);
            }
        }
        if(pass == 5)
        {
            printf("\nTotal swaps in 5th pass: %d",swap5);
        }
    }
    printf("\nSorted Array:");
    for(i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nTotal Swaps are: %d",swap);
}