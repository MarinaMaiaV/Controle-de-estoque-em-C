#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ "estoque.txt"
#define TAM 100

void menu();
void adicionarItem();
void removerItem();
void listarEstoque();

int main() {
    int opcao;
    char continuar;

    do {
        menu();
        printf("Opção: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer

        switch (opcao) {
            case 1:
                adicionarItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarEstoque();
                break;
            case 4:
                printf("\nObrigado por usar o Controle de Estoques! Até a próxima.\n");
                exit(0);
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }

        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &continuar);
        getchar();

    } while (continuar == 's' || continuar == 'S');

    printf("\nObrigado por usar o Controle de Estoques! Até a próxima.\n");
    return 0;
}

void menu() {
    printf("\n==================================\n");
    printf("   Controle de Estoque\n");
    printf("==================================\n");
    printf("1. Adicionar Item\n");
    printf("2. Remover Item\n");
    printf("3. Listar Estoque\n");
    printf("4. Sair\n");
}

void adicionarItem() {
    FILE *fp = fopen(ARQ, "a");
    char nome[TAM];
    int qtd;

    if (!fp) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nDigite o nome do item: ");
    fgets(nome, TAM, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &qtd);
    getchar();

    fprintf(fp, "%s\n%d\n", nome, qtd);
    fclose(fp);

    printf("\nItem adicionado com sucesso!\n");
}

void removerItem() {
    FILE *fp = fopen(ARQ, "r");
    FILE *temp = fopen("temp.txt", "w");

    char nome[TAM], nomeBusca[TAM];
    int qtd, remover;
    int encontrado = 0;

    if (!fp || !temp) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nDigite o nome do item: ");
    fgets(nomeBusca, TAM, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    printf("Digite a quantidade a ser removida: ");
    scanf("%d", &remover);
    getchar();

    while (fgets(nome, TAM, fp)) {
        nome[strcspn(nome, "\n")] = '\0';
        fscanf(fp, "%d\n", &qtd);

        if (strcmp(nome, nomeBusca) == 0) {
            encontrado = 1;

            if (qtd < remover) {
                printf("\nEstoque insuficiente. Quantidade disponível: %d\n", qtd);
                fprintf(temp, "%s\n%d\n", nome, qtd);
            } else {
                qtd -= remover;

                if (qtd == 0) {
                    printf("\nItem removido do estoque!\n");
                } else {
                    fprintf(temp, "%s\n%d\n", nome, qtd);
                    printf("\nQuantidade atualizada com sucesso!\n");
                }
            }
        } else {
            fprintf(temp, "%s\n%d\n", nome, qtd);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(ARQ);
    rename("temp.txt", ARQ);

    if (!encontrado) {
        printf("\nItem não encontrado.\n");
    }
}

void listarEstoque() {
    FILE *fp = fopen(ARQ, "r");
    char nome[TAM];
    int qtd;
    int vazio = 1;

    if (!fp) {
        printf("\nO estoque está vazio.\n");
        return;
    }

    printf("\n=============================\n");
    printf("        Estoque Atual\n");
    printf("=============================\n");

    while (fgets(nome, TAM, fp)) {
        vazio = 0;
        nome[strcspn(nome, "\n")] = '\0';
        fscanf(fp, "%d\n", &qtd);

        printf("Nome: %s\n", nome);
        printf("Quantidade: %d\n\n", qtd);
    }

    if (vazio) {
        printf("O estoque está vazio.\n");
    }

    fclose(fp);
}
