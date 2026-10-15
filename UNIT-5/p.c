#include <stdio.h>

  int graph[5][5] =
  {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0},

  };


  int visited[5] = {0};

  void DFS(int node)
  {
    int i;


    printf("%d", node);
    visited[node] = 1;

    for (i= 0; i < 5; i++)
    {
      if(graph[node][i] == 1 && visited[i] ==0)
      {
       DFS(i);
      }
    }
  }

  void main()
  {
    printf("DFS Traversal: ");

  }
