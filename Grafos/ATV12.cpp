#include <iostream>
#include <vector>
using namespace std;

// Multiplica duas matrizes quadradas
vector<vector<int>> multiplica(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Soma duas matrizes
vector<vector<int>> soma(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

int main() {
    int n;
    cout << "Digite o numero de vertices: ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    cout << "Digite a matriz de adjacencia:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    vector<vector<int>> pot = A; // A^1
    vector<vector<int>> somaPots = A;

    // Calcula A^2 até A^(n-1) e soma
    for (int p = 2; p <= n - 1; p++) {
        pot = multiplica(pot, A);
        somaPots = soma(somaPots, pot);
    }

    // Verifica conectividade
    bool conexo = true;
    for (int i = 0; i < n && conexo; i++)
        for (int j = 0; j < n; j++)
            if (i != j && somaPots[i][j] == 0)
                conexo = false;

    if (conexo)
        cout << "O grafo eh conexo.\n";
    else
        cout << "O grafo NAO eh conexo.\n";

    return 0;
}
