#include <iostream>
#include <vector>

using namespace std;

// Função para validar a matriz de adjacência
bool validarMatrizAdjacencia(const vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        if (matriz[i].size() != n) {
            cout << "Erro: A matriz deve ser quadrada.\n";
            return false;
        }
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                cout << "Erro: A matriz deve conter apenas 0 ou 1.\n";
                return false;
            }
        }
    }
    return true;
}

// Função para converter matriz de adjacência para lista de adjacência
vector<vector<int>> converterParaLista(const vector<vector<int>>& matriz, int n) {
    vector<vector<int>> lista(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == 1) {
                lista[i].push_back(j);
            }
        }
    }
    return lista;
}

// Função para imprimir a lista de adjacência
void imprimirListaAdjacencia(const vector<vector<int>>& lista) {
    cout << "\nLista de adjacência:\n";
    for (int i = 0; i < lista.size(); i++) {
        cout << "Vértice " << i << " -> ";
        for (int v : lista[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Digite o número de vértices: ";
    cin >> n;

    if (n <= 0) {
        cout << "Erro: Número de vértices deve ser positivo.\n";
        return 1;
    }

    vector<vector<int>> matriz(n, vector<int>(n));
    cout << "Digite a matriz de adjacência (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
            if (cin.fail()) {
                cout << "Erro: Entrada inválida.\n";
                return 1;
            }
        }
    }

    if (!validarMatrizAdjacencia(matriz, n)) {
        return 1;
    }

    vector<vector<int>> lista = converterParaLista(matriz, n);
    imprimirListaAdjacencia(lista);

    return 0;
}
