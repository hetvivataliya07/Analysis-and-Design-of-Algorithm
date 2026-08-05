#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printTable(int dp[MAX][MAX], int m, int n, char X[], char Y[]) {
    printf("\nDP Table:\n    ");
    for (int j = 0; j < n; j++)
        printf("  %c", Y[j]);
    printf("\n");

    for (int i = 0; i <= m; i++) {
        if (i == 0)
            printf("  ");
        else
            printf("%c ", X[i-1]);

        for (int j = 0; j <= n; j++)
            printf("%2d ", dp[i][j]);

        printf("\n");
    }
}

int main() {
    char X[MAX], Y[MAX];
    int dp[MAX][MAX];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    printTable(dp, m, n, X, Y);

    int i = m, j = n;
    char lcs[MAX];
    int index = dp[m][n];
    lcs[index] = '\0';

    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs[index - 1] = X[i-1];
            i--; j--; index--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\nLCS = %s", lcs);
    printf("\nLength of LCS = %d\n", dp[m][n]);

    return 0;
}