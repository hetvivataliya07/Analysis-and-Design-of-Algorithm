#include <stdio.h>

#define MAX 100

// Structure for activity
struct Activity {
    int start;
    int finish;
};

// Sort activities by finish time
void sortActivities(struct Activity a[], int n) {
    int i, j;
    struct Activity temp;

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(a[j].finish > a[j+1].finish) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void activitySelection(struct Activity a[], int n) {
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
            if(a[j].finish <= a[i].start && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find index of maximum value
    for(i = 0; i < n; i++) {
        if(dp[i] > max) {
            max = dp[i];
            index = i;
        }
    }

    // Store selected activities in correct order
    struct Activity result[MAX];
    int k = 0;

    while(index != -1) {
        result[k++] = a[index];
        index = prev[index];
    }

    // Print in correct order
    printf("Selected activities:\n");
    for(i = k-1; i >= 0; i--) {
        printf("(%d, %d)\n", result[i].start, result[i].finish);
    }

    printf("Maximum activities: %d\n", max);
}

int main() {
    struct Activity a[MAX];
    int n, i;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    sortActivities(a, n);
    activitySelection(a, n);

    return 0;
}