/// 1. Faça um programa que solicite a idade de uma pessoa. Em seguida, o programa deve exibir uma
// trate dados inválidos, tais como valor negativo.
// mensagem informando se a pessoa é maior de idade. Utilize o tipo de dado mais conveniente e
// ○ Exemplo 1: dada a idade 19, a saída deve ser "Maior de idade".
// ○ Exemplo 2: dada a idade 12, a saída deve ser "Menor de idade".

#include <stdio.h>

int main() {
    int idade;

    // Solicita a idade da pessoa
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // Verifica se a idade é negativa
    if (idade < 0) {
        printf("Por favor, insira uma idade válida (não negativa).\n");
    } else {
        // Verifica se a pessoa é maior de idade
        if (idade >= 18) {
            printf("Maior de idade.\n");
        } else {
            printf("Menor de idade.\n");
        }
    }

    return 0;
}
