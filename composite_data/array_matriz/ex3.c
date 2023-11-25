// 3. Faça uma nova versão do programa anterior para exibir as seguintes informações a partir dos
// valores do vetor: i) mediana; ii) moda; iii) outliers (usando o método Z score); e iv) agrupamento dos
// valores em primeiro, segundo e terceiro quartil.

#include <stdio.h>
#include <math.h>

// Função para calcular a média
float calcularMedia(int conjunto[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; ++i) {
        soma += conjunto[i];
    }

    return (float)soma / tamanho;
}

// Função para calcular a variância
float calcularVariancia(int conjunto[], int tamanho, float media) {
    float somaDiferencasQuadradas = 0.0;

    for (int i = 0; i < tamanho; ++i) {
        float diferenca = conjunto[i] - media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }

    return somaDiferencasQuadradas / tamanho;
}

// Função para calcular o desvio padrão
float calcularDesvioPadrao(float variancia) {
    return sqrt(variancia);
}

// Função para calcular a mediana
float calcularMediana(int conjunto[], int tamanho) {
    // Ordena o vetor
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (conjunto[j] < conjunto[i]) {
                // Troca os elementos
                int temp = conjunto[i];
                conjunto[i] = conjunto[j];
                conjunto[j] = temp;
            }
        }
    }

    // Calcula a mediana
    if (tamanho % 2 == 0) {
        return (conjunto[tamanho / 2 - 1] + conjunto[tamanho / 2]) / 2.0;
    } else {
        return conjunto[tamanho / 2];
    }
}

// Função para calcular a moda
int calcularModa(int conjunto[], int tamanho) {
    int moda = conjunto[0];
    int contagem = 1;
    int maxContagem = 1;

    for (int i = 1; i < tamanho; ++i) {
        if (conjunto[i] == conjunto[i - 1]) {
            contagem++;
        } else {
            contagem = 1;
        }

        if (contagem > maxContagem) {
            maxContagem = contagem;
            moda = conjunto[i];
        }
    }

    return moda;
}

// Função para calcular o Z score
float calcularZScore(int valor, float media, float desvioPadrao) {
    return (valor - media) / desvioPadrao;
}

// Função para calcular o quartil
float calcularQuartil(int conjunto[], int tamanho, int quartil) {
    // Ordena o vetor
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (conjunto[j] < conjunto[i]) {
                // Troca os elementos
                int temp = conjunto[i];
                conjunto[i] = conjunto[j];
                conjunto[j] = temp;
            }
        }
    }

    if (quartil == 1) {
        return conjunto[tamanho / 4];
    } else if (quartil == 2) {
        return conjunto[tamanho / 2];
    } else if (quartil == 3) {
        return conjunto[3 * tamanho / 4];
    } else {
        return -1; // Valor de quartil inválido
    }
}

int main() {
    int tamanho;

    // Solicita o tamanho do conjunto
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &tamanho);

    // Verifica se o tamanho é válido
    if (tamanho <= 0) {
        printf("Por favor, insira um tamanho válido.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Vetor para armazenar os números inteiros
    int conjunto[tamanho];

    // Preenche o vetor com os números inteiros
    printf("Digite os números inteiros:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &conjunto[i]);
    }

    // Calcula a média
    float media = calcularMedia(conjunto, tamanho);

    // Calcula a variância
    float variancia = calcularVariancia(conjunto, tamanho, media);

    // Calcula o desvio padrão
    float desvioPadrao = calcularDesvioPadrao(variancia);

    // Calcula a mediana
    float mediana = calcularMediana(conjunto, tamanho);

    // Calcula a moda
    int moda = calcularModa(conjunto, tamanho);

    // Calcula os Z scores e verifica outliers
    printf("Outliers (valores fora de 2 desvios padrão da média):\n");
    for (int i = 0; i < tamanho; ++i) {
        float zScore = calcularZScore(conjunto[i], media, desvioPadrao);
        if (fabs(zScore) > 2.0) {
            printf("%d (Z Score: %.2f)\n", conjunto[i], zScore);
        }
    }

    // Calcula os quartis
    float primeiroQuartil = calcularQuartil(conjunto, tamanho, 1);
    float segundoQuartil = calcularQuartil(conjunto, tamanho, 2);
    float terceiroQuartil = calcularQuartil(conjunto, tamanho, 3);

    // Exibe os resultados
    printf("\nResultados:\n");
    printf("Média: %.2f\n", media);
    printf("Variância: %.2f\n", variancia);
    printf("Desvio Padrão: %.2f\n", desvioPadrao);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    printf("\nQuartis:\n");
    printf("Primeiro Quartil: %.2f\n", primeiroQuartil);
    printf("Segundo Quartil (Mediana): %.2f\n", segundoQuartil);
    printf("Terceiro Quartil: %.2f\n", terceiroQuartil);

    return 0;
}
