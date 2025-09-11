// Alunos: Ana Clara Nery e Mello Figueiredo e Gustavo Souza Rocha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 11 // TODO: escolha um tamanho adequado (11, 23, 50...)
#define VAZIO (-1)
#define APAGADO (-2)

typedef struct {
    int numero; // numero da Pokedex; -1/-2 para vazio ou apagado
    char nome[50];
    char tipo[20];
} Pokemon;

// TODO: funcao hash (usar resto da divisao)
int h(int chave) {
    return (chave % TAM);
}

// TODO: inicializar tabela (todo numero = VAZIO)
void inicializar(Pokemon *tab) {
    for (int i = 0; i < TAM; i++) {
    tab[i].numero = VAZIO;
    }
}

// TODO: inserir usando sondagem linear
// retorno:
// 1 -> inseriu com sucesso
// 0 -> tabela cheia (falha)
// -1 -> ja existia, nao inseriu
int inserir(Pokemon *tab, int numero, const char *nome, const char *tipo) {
    int pos = h(numero);
    int inicial = pos;

    while (tab[pos].numero != VAZIO && tab[pos].numero != APAGADO) {
        if (tab[pos].numero == numero) {
            return -1; // já existe
        }
        pos = (pos + 1) % TAM;
        if (pos == inicial) return 0; // tabela cheia
    }

    tab[pos].numero = numero;
    strcpy(tab[pos].nome, nome);
    strcpy(tab[pos].tipo, tipo);
    return 1;
}


// TODO: buscar usando sondagem linear
// retorno:
// >=0 -> posicao do pokemon
// -1 -> nao encontrado
int buscar(Pokemon *tab, int numero) {
    int pos = h(numero);
    int inicial = pos;

    while (tab[pos].numero != VAZIO) {
        if (tab[pos].numero == numero) {
            return pos;
        }
        pos = (pos + 1) % TAM;
        if (pos == inicial) break;
    }
    return -1;
}


// TODO: remover (marcar como APAGADO)
int remover_pokemon(Pokemon *tab, int numero) {
    int pos = buscar(tab, numero);
    if (pos >= 0) {
        tab[pos].numero = APAGADO;
        return 1;
    }
    return 0;
}


// TODO: imprimir pokedex ocupada no formato: #num - nome (tipo)
void imprimir_pokedex(Pokemon *tab) {
    for (int i = 0; i < TAM; i++) {
        if (tab[i].numero != VAZIO && tab[i].numero != APAGADO) {
            printf("#%d - %s (%s)\n", tab[i].numero, tab[i].nome, tab[i].tipo);
        }
    }
}


// TODO: imprimir tabela (indices na 1a linha; numeros na 2a)
void imprimir_tabela(Pokemon *tab) {
    printf("Indice: ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
    }
    printf("\nNumero: ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", tab[i].numero);
    }
    printf("\n");
}


int main(void) {
    Pokemon tabela[TAM];
    inicializar(tabela);

    int opcao;
    do {
        printf("\n=== MENU POKEDEX (HASH) ===\n");
        printf("1) Capturar Pokemon\n");
        printf("2) Buscar Pokemon por numero\n");
        printf("3) Remover Pokemon\n");
        printf("4) Listar Pokemons da Pokedex\n");
        printf("5) Imprimir Tabela Hash\n");
        printf("0) Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        system("clear"); // ou system("cls") no Windows

        switch (opcao) {
            case 1: {
                int numero; char nome[50]; char tipo[20];
                printf("\nInforme os dados do Pokemon abaixo.\n");
                printf("Numero: ");
                scanf("%d", &numero);
                printf("Nome: ");
                scanf("%s", nome);
                printf("Tipo: ");
                scanf("%s", tipo);
                int r = inserir(tabela, numero, nome, tipo);
                if (r == 1) printf("Pokemon inserido com sucesso!\n");
                else if (r == -1) printf("Pokemon ja existe na Pokedex.\n");
                else printf("Tabela cheia. Nao foi possivel inserir.\n");
                break;
            }
            case 2: {
                int numero;
                printf("Numero do Pokemon a ser buscado: ");
                scanf("%d", &numero);
                int pos = buscar(tabela, numero);
                if (pos >= 0) {
                    printf("Pokemon encontrado: #%d - %s (%s)\n",
                           tabela[pos].numero, tabela[pos].nome, tabela[pos].tipo);
                } else {
                    printf("Pokemon nao encontrado.\n");
                }
                break;
            }
            case 3: {
                int numero;
                printf("Numero do Pokemon a ser removido: ");
                scanf("%d", &numero);
                int r = remover_pokemon(tabela, numero);
                if (r == 1) printf("Pokemon removido com sucesso.\n");
                else printf("Pokemon nao encontrado.\n");
                break;
            }
            case 4:
                imprimir_pokedex(tabela);
                break;
            case 5:
                imprimir_tabela(tabela);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        char c = getchar();
        while ((c != '\n') && c != EOF); // descarta lixo
        printf("Pressione ENTER para continuar...");
        getchar(); // espera ENTER
        system("clear"); // ou system("cls") no Windows
    } while (opcao != 0);

    return 0;
}
