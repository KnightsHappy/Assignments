#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class GraphList {
    int n;
    std::vector<std::vector<int>> adj;

public:
    GraphList(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void BFS(int start) {
        std::vector<bool> visited(n, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        std::cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        std::cout << "\n";
    }

    void DFS(int start) {
        std::vector<bool> visited(n, false);
        std::stack<int> s;
        s.push(start);

        std::cout << "DFS: ";
        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (!visited[u]) {
                visited[u] = true;
                std::cout << u << " ";
                
                for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                    if (!visited[*it]) s.push(*it);
                }
            }
        }
        std::cout << "\n";
    }
};

int main() {
    int n, e, u, v;
    std::cout << "Enter vertices and edges: ";
    std::cin >> n >> e;
    GraphList g(n);

    std::cout << "Enter edges (u v):\n";
    for(int i=0; i<e; i++) {
        std::cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    std::cout << "Enter start vertex: ";
    std::cin >> start;
    g.BFS(start);
    g.DFS(start);
    return 0;
}
