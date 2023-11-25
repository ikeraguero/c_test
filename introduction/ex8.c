//Faça um programa que solicite n números reais. Em seguida, o programa deve informar os dois
// maiores valores do conjunto de números informados.
// ○ Exemplo, dados os números 14, 3, 10, 2, 1, 8, 15 e 5, a saída esperada é "14 e 15".

#include <stdio.h>
#include <float.h>

int main() {
    int n;

    // Solicita a quantidade de números
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    // Verifica se a quantidade de números é válida
    if (n <= 0) {
        printf("Por favor, insira uma quantidade válida de números.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Variáveis para armazenar os números
    float numero, primeiroMaior = -FLT_MAX, segundoMaior = -FLT_MAX;

    // Solicita os números e encontra os dois maiores
    for (int i = 0; i < n; ++i) {
        printf("Digite o número %d: ", i + 1);
        scanf("%f", &numero);

        // Atualiza os dois maiores valores
        if (numero > primeiroMaior) {
            segundoMaior = primeiroMaior;
            primeiroMaior = numero;
        } else if (numero > segundoMaior) {
            segundoMaior = numero;
        }
    }

    // Exibe os dois maiores valores
    printf("Os dois maiores valores são: %.2f e %.2f\n", primeiroMaior, segundoMaior);

    return 0;
}

