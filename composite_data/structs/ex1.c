// Faça um programa que leia o nome de um produto, o preço e a quantidade comprada e armazene
// estas informações em uma estrutura. Em seguida, o programa deve escrever o nome do produto,
// quantidade, preço unitário e o valor total a ser pago, considerando que são oferecidos diferentes
// descontos com base no número de unidades compradas. Os descontos concedidos devem
// respeitar tabela a seguir:
// a. Até 5 unidades: sem desconto
// b. De 6 a 15 unidades: 10% de desconto
// c. Acima de 16 unidades: 20% de desconto

#include <stdio.h>

// Definindo a estrutura para armazenar informações sobre o produto
struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};

// Função para calcular o valor total com base nos descontos
float calcularValorTotal(struct Produto produto) {
    float valorTotal = produto.preco * produto.quantidade;

    if (produto.quantidade >= 6 && produto.quantidade <= 15) {
        // 10% de desconto
        valorTotal *= 0.9;
    } else if (produto.quantidade > 15) {
        // 20% de desconto
        valorTotal *= 0.8;
    }

    return valorTotal;
}

int main() {
    // Criando uma variável do tipo Produto
    struct Produto produto;

    // Solicitando informações sobre o produto ao usuário
    printf("Digite o nome do produto: ");
    scanf("%s", produto.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);

    printf("Digite a quantidade comprada: ");
    scanf("%d", &produto.quantidade);

    // Calculando o valor total com base nos descontos
    float valorTotal = calcularValorTotal(produto);

    // Exibindo os resultados
    printf("\nResumo da compra:\n");
    printf("Nome do produto: %s\n", produto.nome);
    printf("Quantidade: %d\n", produto.quantidade);
    printf("Preço unitário: R$ %.2f\n", produto.preco);
    printf("Valor total a ser pago: R$ %.2f\n", valorTotal);

    return 0;
}
