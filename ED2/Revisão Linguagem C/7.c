//Pares e Ímpares: https://judge.beecrowd.com/pt/problems/view/1259
//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>
#include <stdlib.h>

int cmpPar(const void *a, const void *b) {
    // ordem crescente
    return (*(int *)a - *(int *)b);
}

int cmpImpar(const void *a, const void *b) {
    // ordem decrescente
    return (*(int *)b - *(int *)a);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    int *pares = malloc(N * sizeof(int));
    int *impares = malloc(N * sizeof(int));
    if (!pares || !impares) return 1;

    int qtdP = 0, qtdI = 0;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0)
            pares[qtdP++] = x;
        else
            impares[qtdI++] = x;
    }

    qsort(pares, qtdP, sizeof(int), cmpPar);
    qsort(impares, qtdI, sizeof(int), cmpImpar);

    for (int i = 0; i < qtdP; i++)
        printf("%d\n", pares[i]);
    for (int i = 0; i < qtdI; i++)
        printf("%d\n", impares[i]);

    free(pares);
    free(impares);
    return 0;
}
