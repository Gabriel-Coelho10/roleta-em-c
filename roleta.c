#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

Node* criarNo(int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (!novo) {
        fprintf(stderr, "Erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

Node* criarRoleta(int n) {
    if (n <= 0) return NULL;
    Node* inicio = NULL;
    Node* temp = NULL;
    for (int i = 1; i <= n; i++) {
        Node* novo = criarNo(i);
        if (inicio == NULL) {
            inicio = novo;
            temp = novo;
        } else {
            temp->prox = novo;
            temp = novo;
        }
    }
    temp->prox = inicio;
    return inicio;
}

void destruirRoleta(Node* inicio, int n) {
    if (!inicio || n <= 0) return;
    Node* atual = inicio;
    for (int i = 0; i < n; i++) {
        Node* prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int girarRoleta(Node* inicio, int passos) {
    if (!inicio) return -1;
    Node* ponteiro = inicio;
    for (int i = 0; i < passos; i++) {
        ponteiro = ponteiro->prox;
    }
    return ponteiro->valor;
}

int main() {
    int nCasas;
    printf("=== Roleta (Lista Encadeada Circular) ===\n");
    printf("Defina o numero de casas (padrao 36). Digite 0 para usar 36: ");
    if (scanf("%d", &nCasas) != 1) {
        fprintf(stderr, "Entrada invalida.\n");
        return EXIT_FAILURE;
    }
    if (nCasas == 0) nCasas = 36;
    if (nCasas < 2) {
        fprintf(stderr, "A roleta precisa de ao menos 2 casas.\n");
        return EXIT_FAILURE;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int escolha;
    printf("Escolha um numero entre 1 e %d: ", nCasas);
    while (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > nCasas) {
        printf("Entrada invalida. Escolha um numero entre 1 e %d: ", nCasas);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    srand((unsigned)time(NULL));

    int voltas = (rand() % 5) + 1;
    int extras = rand() % nCasas;
    int passos = voltas * nCasas + extras;

    Node* roleta = criarRoleta(nCasas);
    int resultado = girarRoleta(roleta, passos);

    printf("\nGiro: %d passos (voltas=%d, extras=%d)\n", passos, voltas, extras);
    printf("A bolinha parou no numero: %d\n", resultado);

    if (resultado == escolha) {
        printf("🎉 Voce ganhou!\n");
    } else {
        printf("❌ Voce perdeu! Tente novamente.\n");
    }

    destruirRoleta(roleta, nCasas);
    return 0;
}
