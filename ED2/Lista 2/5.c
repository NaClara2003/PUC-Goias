#include <stdio.h>
#include <string.h>
//Alunos: Gustavo Rocha e Ana Clara Nery e Mello Figueiredo
#define MAX 5


struct Aluno {
    char nome[50];
    int idade;
    float nota;
};

void imprimirAlunos(struct Aluno v[], int n) {
    printf("--- Lista de Alunos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", v[i].nome);
        printf("Idade: %d\n", v[i].idade);
        printf("Nota: %.2f\n", v[i].nota);
        printf("-----------------------\n");
    }
}

float mediaNotas(struct Aluno v[], int n) {
    float soma = 0.0;
    for (int i = 0; i < n; i++) {
        soma += v[i].nota;
    }
    return soma / n;
}

int main() {

    struct Aluno alunos[MAX];
    int numAlunos;

    printf("Quantos alunos voce quer cadastrar (max %d)? ", MAX);
    scanf("%d", &numAlunos);

    
    printf("\n--- Cadastro de Alunos ---\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Cadastro do Aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Idade: ");
        scanf("%d", &alunos[i].idade);
        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        printf("\n");
    }

    imprimirAlunos(alunos, numAlunos);    
    float media = mediaNotas(alunos, numAlunos);
    printf("Media das notas: %.2f\n", media);
    return 0;
}