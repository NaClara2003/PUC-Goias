#include <iostream>
#include <vector>

using namespace std;

string identificarGrafo(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    vector<int> graus(n, 0);
    int arestas = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graus[i] += matriz[i][j];
            arestas += matriz[i][j];
        }
    }

    arestas /= 2; // evitar contagem duplicada

    bool completo = true, ciclo = true, roda = false;
    for (int i = 0; i < n; i++) {
        if (graus[i] != n - 1) completo = false;
        if (graus[i] != 2) ciclo = false;
    }

    if (!completo && !ciclo) {
        int centro = -1;
        int periferia = 0;
        for (int i = 0; i < n; i++) {
            if (graus[i] == n - 1) centro = i;
            else if (graus[i] == 3) periferia++;
        }
        if (centro != -1 && periferia == n - 1) roda = true;
    }

    if (completo) return "Grafo completo";
    if (ciclo) return "Ciclo";
    if (roda) return "Roda";
    return "Outro tipo de grafo";
}

int main() {
    int n;
    cout << "Digite o número de vértices: ";
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));
    cout << "Digite a matriz de adjacência (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matriz[i][j];

    string tipo = identificarGrafo(matriz);
    cout << "O grafo é: " << tipo << "\n";

    return 0;
}
