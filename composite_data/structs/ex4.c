// Faça um programa que, dadas as posições e dimensões de dois retângulos em um plano
// bidimensional, retorne a área de intersecção entre eles. Se não houver intersecção, deve retornar 0.
// Use estruturas para representar os retângulos em 2D.
// ○ Exemplo: dado os retângulos abaixo, a área de intersecção é 6.
// ■ r1 = { .y = 1, .x = 4, .largura = 3, .altura = 3 }
// ■ r2 = { .y = 0, .x = 5, .largura = 4, .altura = 3 }

#include <stdio.h>

// Estrutura para representar um retângulo em 2D
struct Retangulo {
    int x;
    int y;
    int largura;
    int altura;
};

// Função para calcular a área de interseção entre dois retângulos
int calcularAreaIntersecao(struct Retangulo r1, struct Retangulo r2) {
    // Verifica se há interseção
    if (r1.x + r1.largura < r2.x || r2.x + r2.largura < r1.x ||
        r1.y + r1.altura < r2.y || r2.y + r2.altura < r1.y) {
        return 0; // Não há interseção
    }

    // Calcula a área de interseção
    int xIntersecao = (r1.x > r2.x) ? r1.x : r2.x;
    int yIntersecao = (r1.y > r2.y) ? r1.y : r2.y;
    int larguraIntersecao = (r1.x + r1.largura < r2.x + r2.largura) ? r1.x + r1.largura - xIntersecao : r2.x + r2.largura - xIntersecao;
    int alturaIntersecao = (r1.y + r1.altura < r2.y + r2.altura) ? r1.y + r1.altura - yIntersecao : r2.y + r2.altura - yIntersecao;

    return larguraIntersecao * alturaIntersecao;
}

int main() {
    // Definindo os retângulos
    struct Retangulo r1 = { .x = 4, .y = 1, .largura = 3, .altura = 3 };
    struct Retangulo r2 = { .x = 5, .y = 0, .largura = 4, .altura = 3 };

    // Calculando a área de interseção
    int areaIntersecao = calcularAreaIntersecao(r1, r2);

    // Exibindo o resultado
    printf("A área de interseção entre os retângulos é: %d\n", areaIntersecao);

    return 0;
}
