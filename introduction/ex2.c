// 2. Faça um programa que solicite o nome de uma substância e sua temperatura. Em seguida, o
// programa deve exibir uma mensagem informando o estado físico que a substância se encontra.
// Devem ser consideradas as substâncias água, etanol, ferro, ouro e mercúrio, bem como seus
// respectivos pontos de fusão e ebulição. Utilize os tipos de dado mais convenientes e trate dados
// inválidos, tais como substância desconhecida.
// ○ Exemplo 1: dada a substância água e a temperatura 58º, a saída esperada é "Estado líquido".
// ○ Exemplo 2: dada a substância etanol e a temperatura 80º, a saída esperada é "Estado gasoso".

#include <stdio.h>

int main() {
    // Variáveis para armazenar a substância e a temperatura
    char substancia[20];
    float temperatura;

    // Solicita o nome da substância
    printf("Digite o nome da substância: ");
    scanf("%s", substancia);

    // Solicita a temperatura
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperatura);

    // Verifica a substância e determina o estado físico
    if (strcmp(substancia, "água") == 0) {
        if (temperatura <= 0) {
            printf("Estado sólido\n");
        } else if (temperatura < 100) {
            printf("Estado líquido\n");
        } else {
            printf("Estado gasoso\n");
        }
    } else if (strcmp(substancia, "etanol") == 0) {
        if (temperatura < 78.37) {
            printf("Estado sólido\n");
        } else if (temperatura < 80) {
            printf("Estado líquido\n");
        } else {
            printf("Estado gasoso\n");
        }
    } else if (strcmp(substancia, "ferro") == 0 || strcmp(substancia, "ouro") == 0) {
        printf("Estado sólido\n");
    } else if (strcmp(substancia, "mercúrio") == 0) {
        if (temperatura <= -38.83) {
            printf("Estado sólido\n");
        } else if (temperatura < 356.73) {
            printf("Estado líquido\n");
        } else {
            printf("Estado gasoso\n");
        }
    } else {
        printf("Substância desconhecida\n");
    }

    return 0;
}
