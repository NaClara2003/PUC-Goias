#include <iostream>
#include <vector>

using namespace std;

// Função para validar se a matriz é de adjacência de um grafo não direcionado
bool validarMatriz(const vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] != 0) {
            cout << "Erro: A diagonal deve ser 0 (sem laços).\n";
            return false;
        }
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                cout << "Erro: A matriz deve conter apenas 0 ou 1.\n";
                return false;
            }
            if (matriz[i][j] != matriz[j][i]) {
                cout << "Erro: A matriz deve ser simétrica (grafo não direcionado).\n";
                return false;
            }
        }
    }
    return true;
}

// Função para imprimir o grau de cada vértice
void imprimirGraus(const vector<vector<int>>& matriz, int n) {
    cout << "\nGrau de cada vértice:\n";
    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++) {
            grau += matriz[i][j];
        }
        cout << "Vértice " << i << ": grau " << grau << "\n";
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
                cout << "Erro: Entrada inválida. Use apenas números inteiros.\n";
                return 1;
            }
        }
    }

    if (!validarMatriz(matriz, n)) {
        return 1;
    }

    imprimirGraus(matriz, n);
    return 0;
}
