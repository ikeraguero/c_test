// 2. Faça um programa que leia um conjunto de números inteiros e armazene-os em um vetor que
// representa este conjunto de dados. Em seguida, o programa deve retornar a média, desvio padrão e
// variância dos valores do vetor.

#include <stdio.h>
#include <math.h>

// Função para calcular a média
float calcularMedia(int conjunto[], int tamanho) {
    int soma = 0;

    for (int i = 0; i < tamanho; ++i) {
        soma += conjunto[i];
    }

    return (float)soma / tamanho;
}

// Função para calcular a variância
float calcularVariancia(int conjunto[], int tamanho, float media) {
    float somaDiferencasQuadradas = 0.0;

    for (int i = 0; i < tamanho; ++i) {
        float diferenca = conjunto[i] - media;
        somaDiferencasQuadradas += diferenca * diferenca;
    }

    return somaDiferencasQuadradas / tamanho;
}

// Função para c
