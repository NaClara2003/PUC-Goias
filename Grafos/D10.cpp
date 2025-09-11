#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

bool dfs(int u, int parent) {
    vis[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u)) return true;
        }
        // Se já foi visitado e não é o pai, então há ciclo
        else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Informe o numero de vertices e arestas do grafo:\n";
    int n, m;
    cin >> n >> m;

    adj.assign(n, {});
    vis.assign(n, false);

    cout << "Informe as arestas do grafo (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // não direcionado
    }

    bool ciclo = false;
    for (int i = 0; i < n && !ciclo; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                ciclo = true;
            }
        }
    }

    if (ciclo) {
        cout << "O grafo possui ciclo\n";
    } else {
        cout << "O grafo nao possui ciclo\n";
    }
}
