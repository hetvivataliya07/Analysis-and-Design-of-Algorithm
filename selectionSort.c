//for the given array a = [29,10,14,37,13,7,25,18,3,40,21,6,31,12,2] 
// answer the follwing question 
// 1 arrange the array in asending and desending orader
// 2 calucualte total num of comparisons
// 3 total num swaps
// 4 ans that is it in place algorithm or not [in place]
// 5 ans if it is stable algorithm or not

#include<stdio.h>
#include<conio.h>
void main()
{
    int n = 15 , i,j,min,temp,comp = 0,aswap = 0,dswap = 0;
    int arr[15] = {29,10,14,37,13,7,25,18,3,40,21,6,31,12,2};

    for ( i = 0; i < n-1; i++)
    {
        min = i;
        for ( j = i+1; j < n; j++)
        {
            comp++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            aswap++;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("Ascending order:");
    for ( i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\nTotal Ascending Swap: %d",aswap);
//loop for Descending orader
    for ( i = 0; i < n-1; i++)
    {
        min = i;
        for ( j = i+1; j < n; j++)
        {
            if (arr[j] > arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            dswap++;
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("\nDescending order:");
    for ( i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\nTotal Descending Swap: %d",dswap);
    printf("\nTotal Comparision: %d",comp);
}