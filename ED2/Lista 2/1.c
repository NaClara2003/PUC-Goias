#include <stdio.h>
//Alunos: Gustavo Rocha e Ana CLara Nery e Mello Figueiredo
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void) {
    int x = 10, y = 20;
    trocar(&x, &y);
    return 0;
}