// Faça um programa que leia um conjunto de números inteiros e armazene-os em um vetor, o qual
// representa um conjunto de dados. Em seguida, o programa deve ler novamente um novo conjunto
// de números reais com o mesmo tamanho do conjunto anterior e o armazene em um novo vetor, o
// qual representa um conjunto de pesos. Por fim, o programa deve retornar a média aritmética
// ponderada do conjunto de valores. Todos os vetores devem ser alocados dinamicamente.

#include <stdio.h>
#include <stdlib.h>

// Função para calcular a média aritmética ponderada
float calcularMediaPonderada(const int *valores, const float *pesos, int tamanho) {
    float somaPonderada = 0;
    float somaPesos = 0;

    for (int i = 0; i < tamanho; ++i) {
        somaPonderada += valores[i] * pesos[i];
        somaPesos += pesos[i];
    }

    if (somaPesos == 0) {
        printf("Divisão por zero. Não é possível calcular a média ponderada.\n");
        return 0;
    }

    return somaPonderada / somaPesos;
}

int main() {
    int tamanho;

    // Solicita o tamanho dos vetores
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tamanho);

    if (tamanho <= 0) {
        printf("Tamanho inválido.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Aloca dinamicamente os vetores
    int *valores = (int *)malloc(tamanho * sizeof(int));
    float *pesos = (float *)malloc(tamanho * sizeof(float));

    if (valores == NULL || pesos == NULL) {
        printf("Erro ao alocar memória.\n");

        // Libera a memória alocada, caso uma alocação tenha falhado
        free(valores);
        free(pesos);

        return 1; // Encerra o programa com código de erro 1
    }

    // Preenche o vetor de valores com números inteiros
    printf("Digite os valores inteiros:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Valor[%d]: ", i);
        scanf("%d", valores + i);
    }

    // Preenche o vetor de pesos com números reais
    printf("Digite os pesos (números reais):\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Peso[%d]: ", i);
        scanf("%f", pesos + i);
    }

    // Calcula a média aritmética ponderada
    float mediaPonderada = calcularMediaPonderada(valores, pesos, tamanho);

    // Exibe o resultado
    printf("\nMédia aritmética ponderada: %.2f\n", mediaPonderada);

    // Libera a memória alocada para os vetores
    free(valores);
    free(pesos);

    return 0;
}
