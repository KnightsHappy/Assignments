#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef std::pair<int, int> pii; 

class PrimsGraph {
    int n;
    std::vector<std::vector<pii>> adj;

public:
    PrimsGraph(int nodes) {
        n = nodes;
        adj.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    void findMST() {
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        std::vector<int> key(n, INT_MAX);
        std::vector<int> parent(n, -1);
        std::vector<bool> inMST(n, false);

        int src = 0;
        pq.push({0, src});
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto x : adj[u]) {
                int weight = x.first;
                int v = x.second;

                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        std::cout << "MST Edges:\n";
        int cost = 0;
        for (int i = 1; i < n; ++i) {
            std::cout << parent[i] << " - " << i << "\n";
            cost += key[i];
        }
        std::cout << "Total Cost: " << cost << "\n";
    }
};

int main() {
    int n, e, u, v, w;
    std::cout << "Enter vertices and edges: ";
    std::cin >> n >> e;
    PrimsGraph g(n);
    std::cout << "Enter edges (u v w):\n";
    for(int i=0; i<e; i++) {
        std::cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.findMST();
    return 0;
}
