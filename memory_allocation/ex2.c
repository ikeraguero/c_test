// Faça um programa que encontre o maior e menor inteiro dentro de um vetor inteiros alocado
// dinamicamente. Em seguida, deve ser exibido o maior e menor inteiro e a soma dos dois. Todas as
// operações de manipulação do vetor deve ser realizado a partir da aritmética de ponteiros.

#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior e o menor inteiro em um vetor
void encontrarMaiorMenor(const int *vetor, int tamanho, int *maior, int *menor) {
    if (tamanho <= 0) {
        printf("Vetor vazio.\n");
        return;
    }

    // Inicializa o maior e o menor com o primeiro elemento do vetor
    *maior = *vetor;
    *menor = *vetor;

    // Percorre o vetor para encontrar o maior e o menor
    for (int i = 1; i < tamanho; ++i) {
        if (*(vetor + i) > *maior) {
            *maior = *(vetor + i);
        } else if (*(vetor + i) < *menor) {
            *menor = *(vetor + i);
        }
    }
}

int main() {
    int tamanho;

    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Aloca dinamicamente o vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Preenche o vetor com valores informados pelo usuário
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Vetor[%d]: ", i);
        scanf("%d", vetor + i);
    }

    // Encontra o maior e o menor usando a aritmética de ponteiros
    int maior, menor;
    encontrarMaiorMenor(vetor, tamanho, &maior, &menor);

    // Exibe os resultados
    printf("\nMaior inteiro: %d\n", maior);
    printf("Menor inteiro: %d\n", menor);
    printf("Soma do maior e menor: %d\n", maior + menor);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}
