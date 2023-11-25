// Faça um programa que, dado um vetor de números inteiros v, retorne um novo vetor de forma que
// cada elemento no índice i seja o produto de todos os números no vetor original, com exceção de i.
// ○ Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24].
// ○ Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6].

#include <stdio.h>

// Função para calcular o produto de todos os elementos no vetor, exceto o índice i
int calcularProdutoExcetoIndice(int vetor[], int tamanho, int indice) {
    int produto = 1;

    for (int i = 0; i < tamanho; ++i) {
        if (i != indice) {
            produto *= vetor[i];
        }
    }

    return produto;
}

// Função para gerar o novo vetor com os produtos
void gerarNovoVetor(int vetor[], int tamanho, int novoVetor[]) {
    for (int i = 0; i < tamanho; ++i) {
        novoVetor[i] = calcularProdutoExcetoIndice(vetor, tamanho, i);
    }
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

    // Vetor para armazenar o resultado
    int novoVetor[tamanho];

    // Preenche o vetor com os números inteiros
    printf("Digite os números inteiros:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Gera o novo vetor com os produtos
    gerarNovoVetor(vetor, tamanho, novoVetor);

    // Exibe o novo vetor
    printf("Novo vetor com produtos:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", novoVetor[i]);
    }
    printf("\n");

    return 0;
}
