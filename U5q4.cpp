#include <iostream>
#include <climits>

#define V 10 

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    std::cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < n; i++)
        std::cout << i << " \t " << dist[i] << "\n";
}

int main() {
    int n, graph[V][V];
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    
    std::cout << "Enter Adjacency Matrix (use 0 for no edge):\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            std::cin >> graph[i][j];

    int src;
    std::cout << "Enter source vertex: ";
    std::cin >> src;
    dijkstra(graph, src, n);
    return 0;
}
