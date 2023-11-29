#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
    float unitPrice;
    float totalValue;
};

int main() {
    int numProducts;

    printf("Digite o número de produtos: ");
    scanf("%d", &numProducts);

    struct Product *products = (struct Product *)malloc(numProducts * sizeof(struct Product));

    float totalDiscounts = 0.0;
    for (int i = 0; i < numProducts; i++) {
        printf("\nProduto %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", products[i].name);

        printf("Quantidade: ");
        scanf("%d", &products[i].quantity);

        printf("Preço unitário: ");
        scanf("%f", &products[i].unitPrice);

        products[i].totalValue = products[i].quantity * products[i].unitPrice;


        float discount = 0.0;
        if (products[i].quantity >= 6 && products[i].quantity <= 15) {
            discount = 0.1;  // 10% 
        } else if (products[i].quantity > 15) {
            discount = 0.2;  // 20%
        }

       
        products[i].totalValue -= products[i].totalValue * discount;

       
        totalDiscounts += products[i].totalValue * discount;
    }


    printf("\nProdutos com desconto:\n");
    for (int i = 0; i < numProducts; i++) {
        if (products[i].totalValue < products[i].quantity * products[i].unitPrice) {
            printf("%s\n", products[i].name);
        }
    }

    printf("\nSoma total de descontos concedidos: R$%.2f\n", totalDiscounts);
    free(products);

    return 0;
}
