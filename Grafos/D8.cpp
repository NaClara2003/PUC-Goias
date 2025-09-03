#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool ehBipartito(const vector<vector<int>>& graph, int V) {
    vector<int> color(V, -1); // -1: não colorido, 0 e 1: cores

    for (int start = 0; start < V; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else {
                        if (color[v] == color[u]) {
                        return false; // conflito de cores
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V, E;
    cout << "Digite o número de vértices e arestas: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);

    cout << "Digite as " << E << " arestas (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // grafo não direcionado
    }

    if (ehBipartito(graph, V))
        cout << "O grafo é bipartido.\n";
    else
        cout << "O grafo NÃO é bipartido.\n";

    return 0;
}
