#include <iostream>
#include <vector>

void imprimirErro(const std::string& mensagem) {
    std::cout << "Erro: " << mensagem << "\n";
}

// Função para validar se a matriz é de adjacência de um grafo não direcionado
bool validarMatriz(const std::vector<std::vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] != 0) {
            imprimirErro("A diagonal deve ser 0 (sem laços).");
            return false;
        }
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                imprimirErro("A matriz deve conter apenas 0 ou 1.");
                return false;
            }
            if (matriz[i][j] != matriz[j][i]) {
                imprimirErro("A matriz deve ser simétrica (grafo não direcionado).");
                return false;
            }
        }
    }
    return true;
}

// Função para imprimir o grau de cada vértice
void imprimirGraus(const std::vector<std::vector<int>>& matriz, int n) {
    std::cout << "\nGrau de cada vértice:\n";
    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++) {
            grau += matriz[i][j];
        }
        std::cout << "Vértice " << i << ": grau " << grau << "\n";
    }
}

int main() {
    int n;
    std::cout << "Digite o número de vértices: ";
    std::cin >> n;

    if (n <= 0) {
        imprimirErro("Número de vértices deve ser positivo.");
        return 1;
    }

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    std::cout << "Digite a matriz de adjacência (" << n << "x" << n << "):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz[i][j];
            if (std::cin.fail()) {
                imprimirErro("Entrada inválida. Use apenas números inteiros.");
                return 1;
            }
               return 1;
    }

    imprimirGraus(matriz, n);
    return 0;
}
