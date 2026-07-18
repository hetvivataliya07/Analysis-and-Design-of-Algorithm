#include<stdio.h>
#include<limits.h>

int min(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void main()
{
    int coin[3] = {2,3,4};
    int m = 5, n = 3;
    int dp[n][m];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0)
            {
                dp[i][j] = INT_MAX;
            }
            
            if(j == 0)
            {
                dp[i][j] = 0;
            }

            if(coin[i - 1] > dp[j])
            {
                if(i == 1)
                {
                    dp[i][j] = 1 + dp[i][j - coin[i-1]];  
                }

                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coin[i-1]]);
            }
        }
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            printf(dp[i][j]);
        }
        printf("\n");
    }
}