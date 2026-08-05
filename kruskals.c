#include <stdio.h>
#include <stdlib.h>

// Structure for Edge
struct Edge {
    int u, v, weight;
};

// Function to find parent (Union-Find)
int find(int parent[], int i) {
    if (parent[i] != i)
        return find(parent, parent[i]);
    return i;
}

// Union of two sets
void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Sort edges by weight (Bubble Sort)
void sortEdges(struct Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Dynamic allocation
    struct Edge *edges = (struct Edge *)malloc(e * sizeof(struct Edge));

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges
    sortEdges(edges, e);

    // Parent array for Union-Find
    int *parent = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        parent[i] = i;

    struct Edge *mst = (struct Edge *)malloc((n - 1) * sizeof(struct Edge));

    int count = 0, i = 0;

    // Kruskal's Algorithm
    while (count < n - 1 && i < e) {
        struct Edge current = edges[i++];

        int x = find(parent, current.u);
        int y = find(parent, current.v);

        if (x != y) {
            mst[count++] = current;
            unionSet(parent, x, y);
        }
    }

    printf("\nMinimum Spanning Tree:\n");
    for (int i = 0; i < count; i++) {
        printf("%d - %d \tWeight: %d\n",
               mst[i].u,
               mst[i].v,
               mst[i].weight);
    }

    // Free memory
    free(edges);
    free(parent);
    free(mst);

    return 0;
}