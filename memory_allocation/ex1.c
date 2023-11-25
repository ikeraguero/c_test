// Faça um programa que reproduza o comportamento da função realloc. O programa deve ler um
// conjunto de valores inteiros, armazená-los em um vetor alocado dinamicamente e, em seguida,
// realocar um novo espaço de memória que comporte o dobro de elementos, movendo todo
// conteúdo para este novo espaço de memória.

#include <stdio.h>
#include <stdlib.h>

// Função para imprimir os elementos de um vetor
void imprimirVetor(int *vetor, int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int *vetor = NULL;  // Ponteiro para o vetor
    int tamanho = 0;    // Tamanho atual do vetor

    int valor;
    printf("Digite os valores inteiros (digite -1 para encerrar):\n");

    // Lê os valores até que -1 seja digitado
    while (1) {
        printf("Valor: ");
        scanf("%d", &valor);

        if (valor == -1) {
            break;
        }

        // Realoca a memória para o dobro do tamanho atual
        int *novoVetor = (int *)realloc(vetor, (tamanho + 1) * 2 * sizeof(int));

        if (novoVetor == NULL) {
            printf("Erro ao realocar memória.\n");
            free(vetor); // Libera a memória previamente alocada
            return 1;    // Encerra o programa com código de erro 1
        }

        vetor = novoVetor;  // Atualiza o ponteiro para o novo vetor
        vetor[tamanho] = valor;  // Adiciona o novo valor ao vetor
        tamanho++;  // Incrementa o tamanho do vetor

        imprimirVetor(vetor, tamanho);
    }

    free(vetor); // Libera a memória alocada para o vetor

    return 0;
}
