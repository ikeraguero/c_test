// Faça um programa para manter as informações de uma agenda de contatos utilizando estruturas e
// vetores. O programa deve conter um menu inicial com 5 opções: i) incluir um novo contato; ii)
// excluir um contato existente; iii) alterar um contato existente; iv) listar todos os contatos
// cadastrados; e v) finalizar o programa. A estrutura do contato deve conter um código de
// identificação, nome, e-mail e celular.

#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações sobre um contato
struct Contato {
    int codigo;
    char nome[50];
    char email[50];
    char celular[15];
};

// Função para incluir um novo contato
void incluirContato(struct Contato contatos[], int *numContatos) {
    struct Contato novoContato;

    // Solicita informações sobre o novo contato ao usuário
    printf("Digite o código do contato: ");
    scanf("%d", &novoContato.codigo);

    // Verifica se o código já está cadastrado
    for (int i = 0; i < *numContatos; ++i) {
        if (contatos[i].codigo == novoContato.codigo) {
            printf("Contato com esse código já cadastrado. Operação cancelada.\n");
            return;
        }
    }

    printf("Digite o nome do contato: ");
    scanf("%s", novoContato.nome);

    printf("Digite o e-mail do contato: ");
    scanf("%s", novoContato.email);

    printf("Digite o número de celular do contato: ");
    scanf("%s", novoContato.celular);

    // Adiciona o novo contato ao vetor de contatos
    contatos[*numContatos] = novoContato;
    (*numContatos)++;

    printf("Contato cadastrado com sucesso!\n");
}

// Função para excluir um contato existente
void excluirContato(struct Contato contatos[], int *numContatos) {
    int codigoExcluir;
    printf("Digite o código do contato a ser excluído: ");
    scanf("%d", &codigoExcluir);

    int encontrado = 0;

    // Procura o contato pelo código
    for (int i = 0; i < *numContatos; ++i) {
        if (contatos[i].codigo == codigoExcluir) {
            // Move os contatos subsequentes para preencher o espaço
            for (int j = i; j < *numContatos - 1; ++j) {
                contatos[j] = contatos[j + 1];
            }

            (*numContatos)--;
            encontrado = 1;
            printf("Contato excluído com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

// Função para alterar um contato existente
void alterarContato(struct Contato contatos[], int numContatos) {
    int codigoAlterar;
    printf("Digite o código do contato a ser alterado: ");
    scanf("%d", &codigoAlterar);

    int encontrado = 0;

    // Procura o contato pelo código
    for (int i = 0; i < numContatos; ++i) {
        if (contatos[i].codigo == codigoAlterar) {
            // Solicita as novas informações ao usuário
            printf("Digite o novo nome do contato: ");
            scanf("%s", contatos[i].nome);

            printf("Digite o novo e-mail do contato: ");
            scanf("%s", contatos[i].email);

            printf("Digite o novo número de celular do contato: ");
            scanf("%s", contatos[i].celular);

            encontrado = 1;
            printf("Contato alterado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

// Função para listar todos os contatos cadastrados
void listarContatos(struct Contato contatos[], int numContatos) {
    if (numContatos == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\nLista de contatos cadastrados:\n");
    for (int i = 0; i < numContatos; ++i) {
        printf("Código: %d\n", contatos[i].codigo);
        printf("Nome: %s\n", contatos[i].nome);
        printf("E-mail: %s\n", contatos[i].email);
        printf("Celular: %s\n", contatos[i].celular);
        printf("--------------------\n");
    }
}

int main() {
    struct Contato contatos[100];  // Array para armazenar os contatos
    int numContatos = 0;  // Número atual de contatos cadastrados
    int escolha;

    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1. Incluir novo contato\n");
        printf("2. Excluir contato existente\n");
        printf("3. Alterar contato existente\n");
        printf("4. Listar contatos cadastrados\n");
        printf("5. Finalizar o programa\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                incluirContato(contatos, &numContatos);
                break;
            case 2:
                excluirContato(contatos, &numContatos);
                break;
            case 3:
                alterarContato(contatos, numContatos);
                break;
            case 4:
                listarContatos(contatos, numContatos);
                break;
            case 5:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 5);

    return 0;
}
