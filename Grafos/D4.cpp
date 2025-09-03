#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para validar matriz de adjacência
bool validarMatrizAdjacencia(const vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        if (matriz[i].size() != n) return false;
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != 0 && matriz[i][j] != 1) return false;
        }
    }
    return true;
}

// Função para contar arestas
int contarArestas(const vector<vector<int>>& matriz) {
    int total = 0;
    for (const auto& linha : matriz) {
        for (int val : linha) {
            total += val;
        }
    }
    return total;
}

// Função para verificar isomorfismo
bool saoIsomorfos(const vector<vector<int>>& g1, const vector<vector<int>>& g2, int n) {
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    do {
        bool iguais = true;
        for (int i = 0; i < n && iguais; i++) {
            for (int j = 0; j < n; j++) {
                if (g1[i][j] != g2[perm[i]][perm[j]]) {
                    iguais = false;
                    break;
                }
            }
        }
        if (iguais) return true;
    } while (next_permutation(perm.begin(), perm.end()));

    return false;
}

int main() {
    int n;
    cout << "Digite o número de vértices dos grafos: ";
    cin >> n;

    if (n <= 0) {
        cout << "Erro: número de vértices deve ser positivo.\n";
        return 1;
    }

    vector<vector<int>> g1(n, vector<int>(n));
    vector<vector<int>> g2(n, vector<int>(n));

    cout << "Digite a matriz de adjacência do primeiro grafo:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g1[i][j];

    cout << "Digite a matriz de adjacência do segundo grafo:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g2[i][j];

    if (!validarMatrizAdjacencia(g1, n) || !validarMatrizAdjacencia(g2, n)) {
        cout << "Erro: uma das matrizes é inválida.\n";
        return 1;
    }

    if (contarArestas(g1) != contarArestas(g2)) {
        cout << "Os grafos não são isomorfos (número de arestas diferente).\n";
        return 0;
    }

    if (saoIsomorfos(g1, g2, n)) {
        cout << "Os grafos são isomorfos.\n";
    } else {
        cout << "Os grafos não são isomorfos.\n";
    }

    return 0;
}
