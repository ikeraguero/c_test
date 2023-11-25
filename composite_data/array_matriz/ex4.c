// Faça um programa que, dado um vetor de números inteiros v de tamanho n e um número k, retorne
// verdadeiro se a soma de qualquer par de números em v for igual a k.
// ○ Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17.

#include <stdio.h>

// Função para verificar se a soma de qualquer par é igual a k
int verificaSomaPar(int vetor[], int tamanho, int k) {
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[i] + vetor[j] == k) {
                return 1; // Verdadeiro, pois encontrou um par cuja soma é igual a k
            }
        }
    }
    return 0; // Falso, não encontrou nenhum par cuja soma é igual a k
}

int main() {
    int n, k;

    // Solicita o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Verifica se o tamanho é válido
    if (n <= 0) {
        printf("Por favor, insira um tamanho válido.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Vetor para armazenar os números inteiros
    int vetor[n];

    // Preenche o vetor com os números inteiros
    printf("Digite os números inteiros:\n");
    for (int i = 0; i < n; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Solicita o número k
    printf("Digite o valor de k: ");
    scanf("%d", &k);

    // Verifica se a soma de qualquer par é igual a k
    if (verificaSomaPar(vetor, n, k)) {
        printf("Verdadeiro, existe um par cuja soma é igual a %d.\n", k);
    } else {
        printf("Falso, não existe um par cuja soma é igual a %d.\n", k);
    }

    return 0;
}

