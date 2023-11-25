/// 1. Faça um programa que leia um conjunto de números inteiros e armazene-os em um vetor, o qual
/// representa um conjunto de dados. Em seguida, o programa deve ler novamente um novo conjunto
/// de números reais com o mesmo tamanho do conjunto anterior e o armazene em um novo vetor, o
/// qual representa um conjunto de pesos. Por fim, o programa deve retornar a média aritmética
/// ponderada do conjunto de valores.

#include <stdio.h>

int main() {
    int tamanho;

    // Solicita o tamanho dos conjuntos
    printf("Digite o tamanho dos conjuntos: ");
    scanf("%d", &tamanho);

    // Verifica se o tamanho é válido
    if (tamanho <= 0) {
        printf("Por favor, insira um tamanho válido.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Vetor para armazenar os números inteiros
    int numerosInteiros[tamanho];

    // Vetor para armazenar os números reais (pesos)
    float pesos[tamanho];

    // Preenche o vetor de números inteiros
    printf("Digite os números inteiros:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numerosInteiros[i]);
    }

    // Preenche o vetor de pesos
    printf("Digite os pesos (números reais):\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Peso %d: ", i + 1);
        scanf("%f", &pesos[i]);
    }

    // Calcula a média aritmética ponderada
    float somaPonderada = 0.0;
    float somaPesos = 0.0;

    for (int i = 0; i < tamanho; ++i) {
        somaPonderada += numerosInteiros[i] * pesos[i];
        somaPesos += pesos[i];
    }

    if (somaPesos != 0) {
        float mediaPonderada = somaPonderada / somaPesos;
        printf("A média aritmética ponderada é: %.2f\n", mediaPonderada);
    } else {
        printf("A soma dos pesos é zero, impossível calcular a média ponderada.\n");
    }

    return 0;
}
