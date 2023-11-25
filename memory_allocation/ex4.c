// Faça um programa que leia um conjunto de números inteiros e armazene-os em um vetor que
// representa este conjunto de dados. Em seguida, o programa deve retornar a média, desvio padrão e
// variância dos valores do vetor. O vetor deve ser alocado dinamicamente e manipulado por meio da
// aritmética de ponteiros.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para calcular a média dos valores
float calcularMedia(const int *vetor, int tamanho) {
    float soma = 0;

    for (int i = 0; i < tamanho; ++i) {
        soma += vetor[i];
    }

    return soma / tamanho;
}

// Função para calcular o desvio padrão dos valores
float calcularDesvioPadrao(const int *vetor, int tamanho, float media) {
    float somaQuadrados = 0;

    for (int i = 0; i < tamanho; ++i) {
        somaQuadrados += pow(vetor[i] - media, 2);
    }

    return sqrt(somaQuadrados / tamanho);
}

// Função para calcular a variância dos valores
float calcularVariancia(const int *vetor, int tamanho, float media) {
    float somaQuadrados = 0;

    for (int i = 0; i < tamanho; ++i) {
        somaQuadrados += pow(vetor[i] - media, 2);
    }

    return somaQuadrados / tamanho;
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

    // Calcula a média, desvio padrão e variância usando a aritmética de ponteiros
    float media = calcularMedia(vetor, tamanho);
    float desvioPadrao = calcularDesvioPadrao(vetor, tamanho, media);
    float variancia = calcularVariancia(vetor, tamanho, media);

    // Exibe os resultados
    printf("\nMédia: %.2f\n", media);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);
    printf("Variância: %.2f\n", variancia);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}
