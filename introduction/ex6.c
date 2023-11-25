// Faça um programa que solicite um número positivo. Em seguida, o programa deve informar a
// tabuada de 0 a 10 deste número. Utilize os tipos de dados adequados e trate dados inválidos, tais
// como valores negativos.
// ○ Exemplo, dado o número 7, a saída esperada é "0 x 7 = 0, 1 x 7 = 7, ..., 10 x 7 = 70".

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

    // Exibe a tabuada de 0 a 10 do número fornecido
    printf("Tabuada de %d:\n", numero);
    for (int i = 0; i <= 10; ++i) {
        printf("%d x %d = %d\n", i, numero, i * numero);
    }

    return 0;
}
