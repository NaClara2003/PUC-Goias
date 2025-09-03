#include <stdio.h>
#include <string.h>
//Alunos: Gustavo Rocha e Ana Clara Nery e Mello Figueiredo
struct Aluno {
    char nome[50];
    int idade;
    float nota;
};
void atualizarNota(struct Aluno *a, float nova) {
    a->nota = nova;
}
int main(void) {
    struct Aluno a1 = {"Maria", 20, 8.5f};
    struct Aluno a2 = {"Joao", 22, 7.0f};
    printf("Antes: %s tem nota %.2f\n", a1.nome, a1.nota);
    printf("Antes: %s tem nota %.2f\n", a2.nome, a2.nota);
    atualizarNota(&a1, 9.5f);
    atualizarNota(&a2, 8.0f);
    printf("Depois: %s tem nota %.2f\n", a1.nome, a1.nota);
    printf("Depois: %s tem nota %.2f\n", a2.nome, a2.nota);
    return 0;
}