#include <iostream>
#include <vector>

using namespace std;

// Função para validar a matriz de incidência
bool validarMatrizIncidencia(const vector<vector<int>>& matriz, int n, int m) {
    for (int j = 0; j < m; j++) {
        int origem = 0, destino = 0;
        for (int i = 0; i < n; i++) {
            if (matriz[i][j] == -1) origem++;
            else if (matriz[i][j] == 1) destino++;
            else if (matriz[i][j] != 0) {
                cout << "Erro: Valores inválidos na matriz. Use apenas -1, 0 ou 1.\n";
                return false;
            }
        }
        if (origem != 1 || destino != 1) {
            cout << "Erro: Cada aresta deve ter exatamente um vértice de origem (-1) e um de destino (1).\n";
            return false;
        }
    }
    return true;
}

// Função para calcular e imprimir graus
void imprimirGraus(const vector<vector<int>>& matriz, int n, int m) {
    cout << "\nGrau de entrada e saída de cada vértice:\n";
    for (int i = 0; i < n; i++) {
        int entrada = 0, saida = 0;
        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 1) entrada++;
            else if (matriz[i][j] == -1) saida++;
        }
        cout << "Vértice " << i << ": entrada = " << entrada << ", saída = " << saida << "\n";
    }
}

// Função para converter matriz de incidência para adjacência
vector<vector<int>> converterParaAdjacencia(const vector<vector<int>>& incidencia, int n, int m) {
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int j = 0; j < m; j++) {
        int origem = -1, destino = -1;
        for (int i = 0; i < n; i++) {
            if (incidencia[i][j] == -1) origem = i;
            else if (incidencia[i][j] == 1) destino = i;
        }
        if (origem != -1 && destino != -1) {
            adj[origem][destino] = 1;
        }
    }
    return adj;
}

// Função para imprimir matriz de adjacência
void imprimirMatrizAdjacencia(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    cout << "\nMatriz de adjacência:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cout << "Digite o número de vértices: ";
    cin >> n;
    cout << "Digite o número de arestas: ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Erro: Quantidades devem ser positivas.\n";
        return 1;
    }

    vector<vector<int>> incidencia(n, vector<int>(m));
    cout << "Digite a matriz de incidência (" << n << "x" << m << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> incidencia[i][j];
            if (cin.fail()) {
                cout << "Erro: Entrada inválida.\n";
                return 1;
            }
        }
    }

    if (!validarMatrizIncidencia(incidencia, n, m)) {
        return 1;
    }

    imprimirGraus(incidencia, n, m);

    vector<vector<int>> adjacencia = converterParaAdjacencia(incidencia, n, m);
    imprimirMatrizAdjacencia(adjacencia);

    return 0;
}
