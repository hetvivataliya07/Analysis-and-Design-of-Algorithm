#include <stdio.h>
#include <limits.h>

#define MAX 100

void makeChange(int coins[], int n, int amount) {
    int dp[MAX], coinUsed[MAX];
    int i, j;

    // Initialize
    for(i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
        coinUsed[i] = -1;
    }

    dp[0] = 0;

    // Build DP table
    for(i = 1; i <= amount; i++) {
        for(j = 0; j < n; j++) {
            if(coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if(dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                    coinUsed[i] = coins[j];
                }
            }
        }
    }

    // Check result
    if(dp[amount] == INT_MAX) {
        printf("Change cannot be made with given coins.\n");
        return;
    }

    // Print result
    printf("Minimum coins required: %d\n", dp[amount]);
    printf("Coins used: ");

    int temp = amount;
    while(temp > 0) {
        printf("%d ", coinUsed[temp]);
        temp -= coinUsed[temp];
    }
}

int main() {
    int coins[MAX], n, amount, i;

    printf("Enter number of coin denominations: ");
    scanf("%d", &n);

    printf("Enter coin denominations:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    makeChange(coins, n, amount);

    return 0;
}