#include <stdio.h>

#define MAX 100

void sort(int start[], int finish[], int n) {
    int i, j, temp;

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(finish[j] > finish[j+1]) {

                // swap finish
                temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;

                // swap start
                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }
}

void activitySelection(int start[], int finish[], int n) {
    int dp[MAX], prev[MAX];
    int i, j, max = 0, index = 0;

    // Initialize
    for(i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }

    // DP logic
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(finish[j] <= start[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find maximum
    for(i = 0; i < n; i++) {
        if(dp[i] > max) {
            max = dp[i];
            index = i;
        }
    }

    // Print selected activities (backtracking)
    printf("Selected activities:\n");

    while(index != -1) {
        printf("(%d, %d)\n", start[index], finish[index]);
        index = prev[index];
    }
}

int main() {
    int start[MAX], finish[MAX];
    int n, i;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &start[i]);

    printf("Enter finish times:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &finish[i]);

    sort(start, finish, n);
    activitySelection(start, finish, n);

    return 0;
}