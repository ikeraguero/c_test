// Faça uma nova versão do programa anterior para exibir as seguintes informações a partir dos
// valores do vetor: i) mediana; ii) moda; iii) outliers (usando o método Z score); e iv) agrupamento dos
// valores em primeiro, segundo e terceiro quartil. O vetor deve ser alocado dinamicamente e
// manipulado por meio da aritmética de ponteiros.

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

// Função para comparar valores para a função qsort
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função para calcular a mediana dos valores
float calcularMediana(int *vetor, int tamanho) {
    // Ordena o vetor
    qsort(vetor, tamanho, sizeof(int), comparar);

    // Calcula a mediana
    if (tamanho % 2 == 0) {
        // Se o tamanho do vetor for par, a mediana é a média dos dois valores do meio
        return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
    } else {
        // Se o tamanho do vetor for ímpar, a mediana é o valor do meio
        return vetor[tamanho / 2];
    }
}

// Função para calcular a moda dos valores
void calcularModa(int *vetor, int tamanho) {
    int contagemAtual = 1;
    int contagemMaxima = 1;
    int modaAtual = vetor[0];

    for (int i = 1; i < tamanho; ++i) {
        if (vetor[i] == vetor[i - 1]) {
            contagemAtual++;

            if (contagemAtual > contagemMaxima) {
                contagemMaxima = contagemAtual;
                modaAtual = vetor[i];
            }
        } else {
            contagemAtual = 1;
        }
    }

    printf("Moda: %d\n", modaAtual);
}

// Função para calcular e exibir outliers usando o método Z score
void calcularOutliers(int *vetor, int tamanho, float media, float desvioPadrao) {
    const float Z_SCORE_THRESHOLD = 2.0; // Valor de threshold para considerar um valor como outlier

    printf("Outliers (Z score maior que %.2f):\n", Z_SCORE_THRESHOLD);

    for (int i = 0; i < tamanho; ++i) {
        float zScore = fabs((vetor[i] - media) / desvioPadrao);

        if (zScore > Z_SCORE_THRESHOLD) {
            printf("%d ", vetor[i]);
        }
    }

    printf("\n");
}

// Função para calcular e exibir agrupamento dos valores em quartis
void calcularQuartis(int *vetor, int tamanho) {
    qsort(vetor, tamanho, sizeof(int), comparar);

    printf("\nAgrupamento em quartis:\n");

    int meio = tamanho / 2;

    printf("Primeiro Quartil (Q1): ");
    for (int i = 0; i < meio / 2; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Segundo Quartil (Q2, Mediana): ");
    for (int i = meio / 2; i < meio + tamanho % 2; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Terceiro Quartil (Q3): ");
    for (int i = meio + tamanho % 2; i < tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
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

    // Calcula e exibe a mediana, moda, outliers e agrupamento em quartis
    float media = calcularMedia(vetor, tamanho);
    float desvioPadrao = calcularDesvioPadrao(vetor, tamanho, media);

    printf("\nMédia: %.2f\n", media);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);
    printf("Variância: %.2f\n", calcularVariancia(vetor, tamanho, media));
    printf("Mediana: %.2f\n", calcularMediana(vetor, tamanho));
    calcularModa(vetor, tamanho);
    calcularOutliers(vetor, tamanho, media, desvioPadrao);
    calcularQuartis(vetor, tamanho);

    // Libera a memória alocada para o vetor
    free(vetor);

    return 0;
}
