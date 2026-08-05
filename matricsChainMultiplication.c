#include<stdio.h>
#include<limits.h>

void main()
{
    int n,i,j,k,l;

    printf("Enter number of arrays:");
    scanf("%d",&n);

    int p[n+1];
    printf("Enter Array Dimentions:");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    
    int m[n+1][n+1];
    int s[n+1][n+1];

    for(int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for(int l = 2; l <= n; l++)
    {
        for(int i = 1; i <= n-l+1; i++)
        {
            j=i+l-1;
            m[i][j] = INT_MAX;
            for(int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("DP Table (cost table):\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(j < i)
            {
                printf("0\t");
            }
            else
            {
                printf("%d\t",m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nSelection Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j<=i)
                printf("0\t");
            else
                printf("%d\t",s[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum number of multiplication is: %d", m[1][n]);
}