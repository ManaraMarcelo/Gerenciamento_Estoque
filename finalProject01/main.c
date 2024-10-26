#include <stdio.h>
#include "funcoes.h"

int ler_inteiro();
float ler_float();
void adicionar_produto(Produto *produtos, int *total_produtos);
void listar_produtos(Produto *produtos, int total_produtos);
void editar_produto(Produto *produtos, int total_produtos);
void salvar_estoque(Produto *produtos, int total_produtos);
void carregar_estoque(Produto *produtos, int *total_produtos);

// Função principal que controla o fluxo do programa
int main() {
    Produto produtos[MAX_PRODUTOS];  // Cria um array para armazenar os produtos
    int total_produtos = 0;  // Inicializa o total de produtos no estoque como 0

    carregar_estoque(produtos, &total_produtos);  // Carrega o estoque do arquivo no início do programa

    int opcao;
    do {
        printf("......... MENU .........\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Editar Produto\n");
        printf("4. Salvar e Sair\n");
        printf("........................\n");
        printf("Escolha uma opcao: ");
        opcao = ler_inteiro();  // Lê a escolha do usuário, garantindo que seja um número inteiro

        switch (opcao) {
            case 1:
                printf("\n");
                adicionar_produto(produtos, &total_produtos);  // Adiciona um novo produto ao estoque
                printf("\n");
            break;
            case 2:
                printf("\n");
                listar_produtos(produtos, total_produtos);  // Lista os produtos no estoque
                printf("\n");
            break;
            case 3:
                printf("\n");
                editar_produto(produtos, total_produtos);  // Edita um produto existente
                printf("\n");
            break;
            case 4:
                printf("\n");
                salvar_estoque(produtos, total_produtos);  // Salva o estoque e encerra o programa
                printf("\n");
                printf("Estoque salvo. Saindo...\n");
            break;
            default:
                printf("Opcao invalida. Tente novamente.\n");  // Exibe mensagem para opção inválida
        }
    } while (opcao != 4);  // Repete o loop até que o usuário escolha a opção de sair

    return 0;  // Finaliza o programa
}