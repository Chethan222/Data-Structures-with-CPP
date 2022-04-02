#include <iostream>

int graph[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

int visited[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int i)
{
    std::cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        // Entering if there is connection and not visited
        if (graph[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}
int main()
{
    DFS(1);
    return 0;
}