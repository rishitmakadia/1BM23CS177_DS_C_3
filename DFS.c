#include <stdio.h>
#define MAX 5

void dfs(int adjM[MAX][MAX], int visited[MAX], int start)
{
    int stack[MAX], top = -1, count=1;
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1)
    {
        start = stack[top--];
        printf("%c ", (start + 65));
        for (int k = 0; k < MAX; k++)
        {
            if (adjM[start][k] == 1 && visited[k] == 0)
            {
                stack[++top] = k;
                visited[k] = 1;
                count++;
            }
        }
    }
    if(count==MAX)
        printf("\nConnected Graph");
    else
        printf("\nNot-Connected Graph");
}
int main(){
    int visited[MAX]={0}, adj[MAX][MAX];
    int choice;
    char ch;
    printf("\n1. Insert Graph \t2. DFS Traversal\t3. Exit\t\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Insert Adjacency Matrix of Graph (5 X 5)\n");
                for(int i=0; i<MAX; i++){
                    for(int j=0; j<MAX; j++){
                        scanf("%d", &adj[i][j]);
                    }
                }
                break;
            case 2:
                printf("DFS Traversal\n");
                printf("Enter Starting Node: ");
                scanf(" %c", &ch);
                dfs(adj, visited, (ch-65));
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Invalid Option");
        }
    }
}