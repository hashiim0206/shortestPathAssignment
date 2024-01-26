<<<<<<< HEAD
/*
  Dijikstra   ^`^ys algorithm for finding the shortest path (single-source shortest path).

  Example adapted from:

  https://www.tutorialspoint.com/c-cplusplus-program-for-dijkstra-s-shortest-path-algorithm

 */

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

/* Number of vertices in the graph */
#define V 6

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
   for (int v = 0; v < V; v++)
      if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
void printSolution(int dist[], int prev[]) {
    printf(" ============================================\n");
    printf("|           Dijkstra's algorithm             |\n");
    printf("|        (single-source shortest path)       |\n");
    printf("|                                            |\n");
    printf("|              Source vertex = 0             |\n");
    printf(" --------------------------------------------\n");
    printf("| Vertex | Distance | Path                   |\n");
    printf(" --------------------------------------------\n");
    for (int i = 0; i < V; i++) {
        printf("| %-5d  |%-7d   |%-1d", i, dist[i], i);
        int j = i;
        while (prev[j] != -1) {
            printf(" <- %-1d", prev[j]);
            j = prev[j];

        }
   printf("%-1s |", " ");
    printf("\n");
    }
    printf(" --------------------------------------------\n");
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int prev[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        prev[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u; //keeps track of prev vertices
            }
    }

    printSolution(dist, prev);
}
int main()
{
   int graph[V][V] = {
      { 0,  5,  4,  0,  0, 0 },
      { 5,  0,  6,  3,  0, 0 },
      { 4,  6,  0, 10,  9, 0 },
      { 0,  3, 10,  0,  7, 4 },
      { 0,  0,  9,  7,  0, 8 },
      { 0,  0,  0,  4,  8, 0 }
   };


   dijkstra(graph, 0);

   return 0;
}

>>>>>>> b103745c80047e94943a2768745c8db4e0d166f4
