#include <stdio.h>

void main()
{
  int graph[5][5] =
  {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 0, 1, 1, 0},

  };


  int visited[5] = {0};
  int queue[5];
  int front = 0, rear = 0;
  int i,start =0;

  queue[rear++] =start;
  visited[start] = 1;

  printf("BFS Traversal: ");

  while (front < rear)
  {
      int node = queue[front++];
      printf("%d ", node);

      for (i = 0; i < 5; i++)
      {
          if(graph[node][i] == 1 && visited[i] ==0)
          {
              queue[rear++] = i;
              visited[i] = 1;
          }
      }
  }

}
