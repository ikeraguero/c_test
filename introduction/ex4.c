// Faça um programa que solicite o comprimento de três lados de um triângulo. Em seguida, o
// programa deve informar se o triângulo é equilátero, isósceles ou escaleno. Utilize os tipos de dados
// mais convenientes e trate dados inválidos, tais como valores negativos ou se os comprimentos não
// formam um triângulo.
// ○ Exemplo 1, dado o lado a = 4, b = 4 e c = 4, a saída esperada é equilátero.
// ○ Exemplo 2, dado o lado a = 5, b = 7 e c = 8, a saída esperada é escaleno.

#include <stdio.h>

int main() {
    float a, b, c;

    // Solicita o comprimento dos lados do triângulo
    printf("Digite o comprimento do lado a: ");
    scanf("%f", &a);
    printf("Digite o comprimento do lado b: ");
    scanf("%f", &b);
    printf("Digite o comprimento do lado c: ");
    scanf("%f", &c);

    // Verifica se os comprimentos formam um triângulo
    if (a + b > c && a + c > b && b + c > a) {
        // Classifica o triângulo
        if (a == b && b == c) {
            printf("Equilátero\n");
        } else if (a == b || a == c || b == c) {
            printf("Isósceles\n");
        } else {
            printf("Escaleno\n");
        }
    } else {
        printf("Os comprimentos fornecidos não formam um triângulo.\n");
    }

    return 0;
}
