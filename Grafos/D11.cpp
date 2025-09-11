#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Informe o numero de vertices e arestas do grafo:\n";
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Informe as arestas do grafo (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // não direcionado
    }

    cout << "Informe o vertice inicial:\n";
    int start;
    cin >> start;

    vector<int> dist(n, -1); // -1 significa "não alcançável"
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) { // ainda não visitado
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "Distancias a partir do vertice " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertice " << i << ": ";
        if (dist[i] == -1) cout << "inacessivel\n";
        else cout << dist[i] << "\n";
    }
}
