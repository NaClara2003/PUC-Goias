#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis, pilha;

bool dfs(int u) {
    vis[u] = true;
    pilha[u] = true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v)) return true;
        } 
        else if (pilha[v]) {
            return true; // ciclo encontrado
        }
    }

    pilha[u] = false;
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
    pilha.assign(n, false);

    cout << "Informe as arestas do grafo:\n";
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // grafo direcionado
    }

    bool flag = false;
    for (int i = 0; i < n && !flag; i++) {
        if (!vis[i]) {
            flag = dfs(i);
        }
    }

    if (flag) {
        cout << "O grafo é cíclico\n";
    } else {
        cout << "O grafo não é cíclico\n";
    }
}
