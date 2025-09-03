#include <stdio.h>
//Alunos: Gustavo Rocha e Ana Clara Nery e Mello Figueiredo
int soma(int v[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += v[i];
    }
    return total;
}
int main(void) {
    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", soma(v, 10));
    return 0;
}