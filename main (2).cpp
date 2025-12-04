#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>
using namespace std;

typedef pair<int, string> pis;

int main() {
    map<string, vector<pair<string,int>>> graph;

    graph["Medan"] = {{"Tebing Tinggi",70}, {"Brastagi",60}};
    graph["Tebing Tinggi"] = {{"Pematangsiantar",50}};
    graph["Brastagi"] = {{"Sidikalang",90},{"Pematangsiantar",80}};
    graph["Pematangsiantar"] = {{"Parapat",45},{"Sidikalang",65}};
    graph["Sidikalang"] = {{"Parapat",120}};

    string start, end;
    cout << "Masukkan kota asal: ";
    getline(cin, start);
    cout << "Masukkan kota tujuan: ";
    getline(cin, end);

    map<string, int> dist;
    map<string, string> parent;

    for (auto &city : graph)
        dist[city.first] = INT_MAX;

    dist[start] = 0;

    priority_queue<pis, vector<pis>, greater<pis>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int d = pq.top().first;
        string u = pq.top().second;
        pq.pop();

        for (auto &neighbor : graph[u]) {
            string v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<string> path;
    for (string v = end; v != ""; v = parent[v])
        path.push_back(v);

    cout << "\nJalur Terpendek:\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }

    cout << "\nTotal Jarak: " << dist[end] << " km\n";

    return 0;
}