// Faça um programa que, dado um vetor de números inteiros v, retorne o máximo divisor comum
// entre os números do vetor.
// ○ Exemplo: dado v = [46,56,14], a saída esperada é 14.

#include <stdio.h>

// Função para calcular o MDC de dois números usando o Algoritmo de Euclides
int calcularMDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular o MDC de um vetor de números inteiros
int calcularMDCVetor(int vetor[], int tamanho) {
    if (tamanho <= 0) {
        return -1; // Tamanho inválido
    }

    int mdc = vetor[0];

    for (int i = 1; i < tamanho; ++i) {
        mdc = calcularMDC(mdc, vetor[i]);
    }

    return mdc;
}

int main() {
    int tamanho;

    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Verifica se o tamanho é válido
    if (tamanho <= 0) {
        printf("Por favor, insira um tamanho válido.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Vetor para armazenar os números inteiros
    int vetor[tamanho];

    // Preenche o vetor com os números inteiros
    printf("Digite os números inteiros:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Calcula o MDC do vetor
    int mdc = calcularMDCVetor(vetor, tamanho);

    // Exibe o resultado
    if (mdc != -1) {
        printf("O máximo divisor comum (MDC) é: %d\n", mdc);
    } else {
        printf("Tamanho inválido do vetor.\n");
    }

    return 0;
}
