#include <iostream>
#include <queue>

class GraphMatrix {
    int adj[20][20];
    int visited[20];
    int n;

public:
    void createGraph() {
        std::cout << "Enter number of vertices: ";
        std::cin >> n;
        std::cout << "Enter adjacency matrix:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                std::cin >> adj[i][j];
    }

    void BFS(int start) {
        std::fill(visited, visited + n, 0);
        std::queue<int> q;
        q.push(start);
        visited[start] = 1;

        std::cout << "BFS: ";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            std::cout << curr << " ";

            for (int i = 0; i < n; i++) {
                if (adj[curr][i] == 1 && !visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        std::cout << "\n";
    }

    void DFSUtil(int v) {
        visited[v] = 1;
        std::cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                DFSUtil(i);
            }
        }
    }

    void DFS(int start) {
        std::fill(visited, visited + n, 0);
        std::cout << "DFS: ";
        DFSUtil(start);
        std::cout << "\n";
    }
};

int main() {
    GraphMatrix g;
    g.createGraph();
    int start;
    std::cout << "Enter start vertex: ";
    std::cin >> start;
    g.BFS(start);
    g.DFS(start);
    return 0;
}
