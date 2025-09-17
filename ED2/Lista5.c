//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =========================================================
//   POKEDEX — Tabela Hash com Lista Encadeada (Separate Chaining)
//   ---------------------------------------------------------
//   Objetivo:
//   - Implementar TABELA HASH com tratamento de colisões por
//     LISTA ENCADEADA (separate chaining).
//   - Cada posição do vetor (bucket) guarda o início de uma lista.
//   - Colisões viram nós adicionais no mesmo bucket.
// =========================================================

#define TAM 11  // número primo ajuda na distribuição

// Estrutura do dado armazenado (registro da Pokédex)
typedef struct {
    int  numero;       // chave (número da Pokédex)
    char nome[50];
    char tipo[20];
} Pokemon;

// Nó da lista de cada bucket
typedef struct Node {
    Pokemon      registro;   // dado do nó
    struct Node *next;       // próximo nó
} Node;

// ======================== PROTÓTIPOS ========================
int  h(int chave);
void inicializar(Node *tab[]);
int  buscar(Node *tab[], int numero);
int  inserir(Node *tab[], int numero, const char *nome, const char *tipo);
int  remover_pokemon(Node *tab[], int numero);
void imprimir_pokedex(Node *tab[]);
void imprimir_tabela(Node *tab[]);
// ============================================================

// Função hash
// O que fazer: calcular índice do bucket (0..TAM-1)
int h(int chave) {
    return (chave % TAM);
}

// Inicialização da tabela
// O que fazer: colocar NULL em todas as posições do vetor
void inicializar(Node *tab[]) {
    // TODO: definir tab[i] = NULL para todo i
}

// Buscar por número
// O que fazer:
// - Calcular bucket com h(numero)
// - Percorrer lista encadeada
// - Se encontrar, retornar índice do bucket
// - Caso contrário, retornar -1
int buscar(Node *tab[], int numero) {
    // TODO: implementar busca
    return -1; // placeholder
}

// Inserir novo registro
// O que fazer:
// - Se já existir (buscar), retornar -1
// - Calcular idx = h(numero)
// - Alocar nó (malloc)
// - Copiar numero, nome e tipo para novo->registro
// - Encadear no início da lista: novo->next = tab[idx]
// - tab[idx] = novo
// - Retornar 1 se deu certo; 0 se falhar
int inserir(Node *tab[], int numero, const char *nome, const char *tipo) {
    // TODO: implementar inserção
    return 0; // placeholder
}

// Remover por número
// O que fazer:
// - Calcular idx = h(numero)
// - Percorrer lista guardando anterior e atual
// - Ao encontrar, religar a lista e liberar nó
// - Retornar 1 se removeu; 0 se não achou
int remover_pokemon(Node *tab[], int numero) {
    // TODO: implementar remoção
    return 0; // placeholder
}

// Imprimir Pokedex (todos os registros)
// Implementação fornecida
void imprimir_pokedex(Node *tab[]) {
    int vazio = 1;
    for (int i = 0; i < TAM; i++) {
        for (Node *p = tab[i]; p != NULL; p = p->next) {
            printf("#%d - %s (%s)\n",
                   p->registro.numero, p->registro.nome, p->registro.tipo);
            vazio = 0;
        }
    }
    if (vazio) printf("(Pokedex vazia)\n");
}

// Imprimir Tabela (cadeias por bucket)
// Implementação fornecida
void imprimir_tabela(Node *tab[]) {
    for (int i = 0; i < TAM; i++) {
        printf("[%d]: ", i);
        if (!tab[i]) {
            printf("-\n");
            continue;
        }
        Node *p = tab[i];
        while (p) {
            printf("%d", p->registro.numero);
            p = p->next;
            if (p) printf(" -> ");
        }
        printf("\n");
    }
}

// ========================= DEMO / MENU =========================
int main(void) {
    Node *tabela[TAM];
    inicializar(tabela);

    int opcao;
    do {
        printf("\n=== MENU POKEDEX (HASH + LISTA) ===\n");
        printf("1) Capturar Pokemon\n");
        printf("2) Buscar Pokemon por numero\n");
        printf("3) Remover Pokemon\n");
        printf("4) Listar Pokemons da Pokedex\n");
        printf("5) Imprimir Tabela Hash (cadeias)\n");
        printf("0) Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) return 0;

        switch (opcao) {
            case 1: {
                int numero; char nome[50]; char tipo[20];

                printf("\nInforme os dados do Pokemon abaixo.\n");

                // Leitura do número
                printf("Numero: ");
                scanf("%d", &numero);
                int c; while ((c = getchar()) != '\n' && c != EOF);

                // Leitura do nome
                printf("Nome: ");
                if (fgets(nome, sizeof(nome), stdin)) {
                    nome[strcspn(nome, "\n")] = '\0';
                }

                // Leitura do tipo
                printf("Tipo: ");
                if (fgets(tipo, sizeof(tipo), stdin)) {
                    tipo[strcspn(tipo, "\n")] = '\0';
                }

                int r = inserir(tabela, numero, nome, tipo);
                
                if (r == 1)
                    printf("Inserido com sucesso.\n");
                else if (r == -1)
                    printf("Ja existe esse numero na Pokedex.\n");
                else
                    printf("Falha ao inserir (ou funcao nao implementada).\n");
                
                break;
            }
            case 2: {
                int numero;
                printf("Numero do Pokemon a ser buscado: ");
                scanf("%d", &numero);
                int pos = buscar(tabela, numero);
                
                if (pos >= 0)
                    printf("Encontrado no bucket %d.\n", pos);
                else
                    printf("Nao encontrado.\n");
                    
                break;
            }
            case 3: {
                int numero;
                printf("Numero do Pokemon a ser removido: ");
                scanf("%d", &numero);
                
                if (remover_pokemon(tabela, numero))
                    printf("Removido.\n");
                else
                    printf("Nao encontrado (ou funcao nao implementada).\n");
                
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

        int ch; while ((ch = getchar()) != '\n' && ch != EOF);
        printf("Pressione ENTER para continuar...");
        getchar();
        // Opcional: limpar a tela
        // - Linux / Mac: system("clear");
        // - Windows:     system("cls");
        // Descomente a linha adequada ao seu sistema operacional
        // system("clear");
        // system("cls");

    } while (opcao != 0);

    // Liberação de memória
    // O que fazer:
    // - Percorrer cada bucket i
    // - Percorrer lista liberando nós com free
    for (int i = 0; i < TAM; i++) {
        // TODO: liberar lista do bucket i
    }

    return 0;
}
