// Faça um programa que solicite um número positivo. Em seguida, o programa deve exibir os números
// pares de 0 até o número informado pelo usuário. Utilize os tipos de dados adequados e trate dados
// inválidos, tais como valores negativos.
// ○ Exemplo, dado o número 10, a saída é "2, 4, 6, 8, 10".

#include <stdio.h>

int main() {
    int numero;

    // Solicita um número positivo
    printf("Digite um número positivo: ");
    scanf("%d", &numero);

    // Verifica se o número é positivo
    if (numero < 0) {
        printf("Por favor, insira um número positivo.\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Exibe os números pares de 0 até o número informado
    printf("Números pares de 0 até %d:\n", numero);
    for (int i = 0; i <= numero; i += 2) {
        printf("%d", i);
        if (i < numero - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}



