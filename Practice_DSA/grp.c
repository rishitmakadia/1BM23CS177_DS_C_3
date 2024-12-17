
// #include <stdio.h>
// #define MAX 5

// void bfs(int adj[][MAX], int visited[], int start) {
//     int queue[MAX], rear = -1, front = -1, i;

//     // Initialize all vertices as not visited
//     for (i = 0; i < MAX; i++) {
//         visited[i] = 0;
//     }

//     // Enqueue the start vertex and mark it as visited
//     queue[++rear] = start;
//     front++;
//     visited[start] = 1;

//     printf("BFS Traversal: ");

//     while (rear >= front) {
//         // Dequeue the vertex
//         start = queue[front++];
//         printf("%d ", start);

//         // Visit all adjacent vertices
//         for (i = 0; i < MAX; i++) {
//             if (adj[start][i] && visited[i] == 0) {
//                 queue[++rear] = i;  // Enqueue the vertex
//                 visited[i] = 1;     // Mark as visited
//             }
//         }
//     }
//     printf("\n");
// }

// int main() {
//     int adj[MAX][MAX], visited[MAX];
//     int i, j, start;
//     printf("Enter the adjacency matrix for the graph (%dx%d):\n", MAX, MAX);
//     for (i = 0; i < MAX; i++) {
//         for (j = 0; j < MAX; j++) {
//             scanf("%d", &adj[i][j]);
//         }
//     }
//     printf("Enter the starting vertex for BFS (0 to %d): ", MAX - 1);
//     scanf("%d", &start);
//     bfs(adj, visited, start);
//     return 0;
// }


#include <stdio.h>
#define MAX 10

void dfs(int adj[][MAX], int visited[], int vertex, int n) {
    visited[vertex] = 1;  // Mark the current vertex as visited

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0) {  // If there is an edge and the vertex is not visited
            dfs(adj, visited, i, n);  // Recursively call DFS for the adjacent vertex
        }
    }
}

int isConnected(int adj[][MAX], int n) {
    int visited[MAX] = {0};  // Array to keep track of visited vertices

    // Start DFS from the first vertex (vertex 0)
    dfs(adj, visited, 0, n);

    // Check if all vertices were visited
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return 0;  // If any vertex is not visited, the graph is not connected
        }
    }

    return 1;  // All vertices were visited, so the graph is connected
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (isConnected(adj, n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}
