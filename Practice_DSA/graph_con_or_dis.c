#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// DFS-based function to check if the graph is connected
bool isConnected(int totalNodes, int adjMatrix[MAX_NODES][MAX_NODES]) {
    bool visited[MAX_NODES] = {false};
    int stack[MAX_NODES], top = -1;
    int visitedCount = 0;

    // Start DFS from node 0 by pushing it onto the stack
    stack[++top] = 0;
    visited[0] = true;

    while (top >= 0) {
        int currentNode = stack[top--];
        visitedCount++;

        // Visit all adjacent nodes
        for (int i = 0; i < totalNodes; i++) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;
                stack[++top] = i;
            }
        }
    }

    // Check if all nodes have been visited
    return visitedCount == totalNodes;
}

int main() {
    int nodes;
    int adjMatrix[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the adjacency matrix (%d x %d):\n", nodes, nodes);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    if (isConnected(nodes, adjMatrix)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
