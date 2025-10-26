#include <stdio.h>
#include <stdlib.h>

// Função que cria dinamicamente um vetor de n elementos e retorna o ponteiro
int* cria_vetor(int n) {
    int* vetor = (int*) malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    return vetor;
}

// Função que imprime os n elementos do vetor
void imprime_vetor(int* vetor, int n) {
    printf("\nElementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função que libera a memória alocada
void libera_vetor(int* vetor) {
    free(vetor);
}

int main() {
    int n;
    int* vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Cria o vetor dinamicamente
    vetor = cria_vetor(n);

    // Lê os elementos do vetor
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Imprime o vetor
    imprime_vetor(vetor, n);

    // Libera a memória
    libera_vetor(vetor);

    printf("\nMemória liberada com sucesso.\n");

    return 0;
}
