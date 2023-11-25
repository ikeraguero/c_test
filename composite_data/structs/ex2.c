// Faça um programa para cadastrar veículos. O programa deve conter um menu inicial com opções
// para incluir um novo veículo, listar todos os veículos cadastrados e finalizar o programa. A estrutura
// do veículo deve conter a placa, categoria (carro, moto, ônibus, caminhão,etc.), modelo e o ano. Não
// pode haver veículos com placas idênticas. Use enumeradores para descrever as categorias dos
// veículos.

#include <stdio.h>
#include <string.h>

// Enumerador para as categorias de veículos
enum Categoria {
    CARRO,
    MOTO,
    ONIBUS,
    CAMINHAO
};

// Estrutura para armazenar informações sobre um veículo
struct Veiculo {
    char placa[10];
    enum Categoria categoria;
    char modelo[50];
    int ano;
};

// Função para incluir um novo veículo
void incluirVeiculo(struct Veiculo veiculos[], int *numVeiculos) {
    struct Veiculo novoVeiculo;

    // Solicita informações sobre o novo veículo ao usuário
    printf("Digite a placa do veículo: ");
    scanf("%s", novoVeiculo.placa);

    // Verifica se a placa já está cadastrada
    for (int i = 0; i < *numVeiculos; ++i) {
        if (strcmp(veiculos[i].placa, novoVeiculo.placa) == 0) {
            printf("Veículo com essa placa já cadastrado. Operação cancelada.\n");
            return;
        }
    }

    printf("Escolha a categoria do veículo (0 - Carro, 1 - Moto, 2 - Ônibus, 3 - Caminhão): ");
    scanf("%d", (int *)&novoVeiculo.categoria);

    printf("Digite o modelo do veículo: ");
    scanf("%s", novoVeiculo.modelo);

    printf("Digite o ano do veículo: ");
    scanf("%d", &novoVeiculo.ano);

    // Adiciona o novo veículo ao vetor de veículos
    veiculos[*numVeiculos] = novoVeiculo;
    (*numVeiculos)++;

    printf("Veículo cadastrado com sucesso!\n");
}

// Função para listar todos os veículos cadastrados
void listarVeiculos(struct Veiculo veiculos[], int numVeiculos) {
    if (numVeiculos == 0) {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    printf("\nLista de veículos cadastrados:\n");
    for (int i = 0; i < numVeiculos; ++i) {
        printf("Veículo %d:\n", i + 1);
        printf("Placa: %s\n", veiculos[i].placa);
        printf("Categoria: %d\n", veiculos[i].categoria);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Ano: %d\n", veiculos[i].ano);
        printf("--------------------\n");
    }
}

int main() {
    struct Veiculo veiculos[100];  // Array para armazenar os veículos
    int numVeiculos = 0;  // Número atual de veículos cadastrados
    int escolha;

    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Incluir novo veículo\n");
        printf("2. Listar veículos cadastrados\n");
        printf("3. Finalizar o programa\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                incluirVeiculo(veiculos, &numVeiculos);
                break;
            case 2:
                listarVeiculos(veiculos, numVeiculos);
                break;
            case 3:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 3);

    return 0;
}
