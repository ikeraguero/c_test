// Faça um programa que reproduza a árvore de decisão abaixo para indicar se as condições
// climáticas estão favoráveis ou não para jogar tênis. Utilize tipos de dado mais convenientes e trate
// situações de dados inválidos, bem como solicitar informações irrelevantes para um dado fluxo.
// ○ Exemplo 1, ao informar a situação sol e umidade elevada, a saída esperada é não.
// ○ Exemplo 2, ao informar a situação nuvens, a saída esperada é sim.

#include <stdio.h>
#include <string.h>

int main() {
    char situacao[20];
    char outlook[20];
    char umidade[20];

    // Solicita informações sobre a situação climática
    printf("Informe a situação (sol, nuvens, chuva): ");
    scanf("%s", situacao);

    // Verifica a situação e avança na árvore de decisão
    if (strcmp(situacao, "sol") == 0) {
        // Solicita informações adicionais para a situação de sol
        printf("Informe a umidade (baixa, normal, alta): ");
        scanf("%s", umidade);

        // Verifica a umidade
        if (strcmp(umidade, "alta") == 0) {
            printf("Não\n");
        } else {
            printf("Sim\n");
        }
    } else if (strcmp(situacao, "nuvens") == 0) {
        printf("Sim\n");
    } else if (strcmp(situacao, "chuva") == 0) {
        // Solicita informações adicionais para a situação de chuva
        printf("Informe a previsão (fraca, moderada, forte): ");
        scanf("%s", outlook);

        // Verifica a previsão
        if (strcmp(outlook, "fraca") == 0) {
            printf("Sim\n");
        } else {
            printf("Não\n");
        }
    } else {
        printf("Informe uma situação válida (sol, nuvens, chuva)\n");
    }

    return 0;
}
