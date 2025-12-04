#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, wDist, wCost;
};

int main() {
    int V, E, start;
    cin >> V >> E >> start;

    vector<Edge> edges(E);

    for(int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v
            >> edges[i].wDist >> edges[i].wCost;
    }

    vector<int> dist(V + 1, INT_MAX);
    vector<int> cost(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);

    dist[start] = 0;
    cost[start] = 0;

    for(int i = 1; i <= V - 1; i++) {
        for(auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.wDist < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.wDist;
                cost[e.v] = cost[e.u] + e.wCost;
                parent[e.v] = e.u;
            }
        }
    }

    cout << "\nJarak (meter): ";
    for(int i = 1; i <= V; i++)
        cout << dist[i] << " ";

    cout << "\nBiaya (rupiah): ";
    for(int i = 1; i <= V; i++)
        cout << cost[i] << " ";

    int target = V;
    vector<int> path;
    for (int v = target; v != -1; v = parent[v])
        path.push_back(v);

    cout << "\nJalur ke kos " << target << ": ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " -> ";

    cout << "Sampai\n";

    return 0;
}