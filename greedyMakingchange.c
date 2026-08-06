#include <stdio.h>
#include <limits.h>

#define MAX 100

// Structure to store result
struct Change {
    int minCoins;
    int coinsUsed[MAX];
};

// Function using Dynamic Programming
struct Change makeChange(int coins[], int n, int amount) {
    int dp[MAX], coinUsed[MAX];
    struct Change result;
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

    // Store result
    result.minCoins = dp[amount];

    // Track coins used
    int k = 0;
    int temp = amount;

    while(temp > 0 && coinUsed[temp] != -1) {
        result.coinsUsed[k++] = coinUsed[temp];
        temp -= coinUsed[temp];
    }

    result.coinsUsed[k] = 0; // mark end

    return result;
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

    struct Change res = makeChange(coins, n, amount);

    if(res.minCoins == INT_MAX) {
        printf("Change cannot be made with given coins.\n");
    } else {
        printf("Minimum coins required: %d\n", res.minCoins);
        printf("Coins used: ");
        for(i = 0; res.coinsUsed[i] != 0; i++) {
            printf("%d ", res.coinsUsed[i]);
        }
    }

    return 0;
}