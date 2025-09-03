#include <stdio.h>
//Alunos: Gustavo Rocha e Ana Clara Nery e Mello Figueiredo
void dobrarMatriz(int m[][3], int linhas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < 3; j++) {
            m[i][j] *= 2;
        }
    }
}
int main(void) {
    int M[2][3] = { {1,2,3}, {4,5,6} };
    dobrarMatriz(M, 2);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}