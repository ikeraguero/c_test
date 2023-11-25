// Faça um programa que solicite o salário de um funcionário no regime CLT. Em seguida, o programa
// deve informar a alíquota do Imposto de Renda e o salário bruto após a dedução do imposto. Utilize
// os tipos de dados mais convenientes e trate dados inválidos, tais como salário negativo. Além
// disso, considere também a parcela a deduzir do Imposto de Renda.
// ○ Exemplo 1, dado o salário R$ 1.500,00, a saída esperada é isento e R$ 1.500,00.
// ○ Exemplo 2, dado o salário R$ 3.500,00, a saída esperada é 15% e R$ 3.329,80.
// ■ 3.500,00 - (3.500,00 * 0,15 - 354,80) = 3.329,80

#include <stdio.h>

int main() {
    float salario;

    // Solicita o salário do funcionário
    printf("Digite o salário do funcionário: R$ ");
    scanf("%f", &salario);

    // Verifica se o salário é negativo
    if (salario < 0) {
        printf("Por favor, insira um salário válido (não negativo).\n");
        return 1; // Encerra o programa com código de erro 1
    }

    // Calcula o Imposto de Renda
    float ir_aliquota, ir_deduzir, salario_liquido;
    if (salario <= 1903.98) {
        ir_aliquota = 0;
        ir_deduzir = 0;
    } else if (salario <= 2826.65) {
        ir_aliquota = 7.5;
        ir_deduzir = 142.80;
    } else if (salario <= 3751.05) {
        ir_aliquota = 15;
        ir_deduzir = 354.80;
    } else if (salario <= 4664.68) {
        ir_aliquota = 22.5;
        ir_deduzir = 636.13;
    } else {
        ir_aliquota = 27.5;
        ir_deduzir = 869.36;
    }

    // Calcula o salário líquido
    salario_liquido = salario - (salario * ir_aliquota / 100 - ir_deduzir);

    // Exibe os resultados
    printf("Alíquota do Imposto de Renda: %.2f%%\n", ir_aliquota);
    printf("Salário bruto após dedução do Imposto de Renda: R$ %.2f\n", salario_liquido);

    return 0;
}
