#include <stdio.h>
#include "funcoes.h"

int ler_inteiro();
float ler_float();
void adicionar_produto(Produto *produtos, int *total_produtos);
void listar_produtos(Produto *produtos, int total_produtos);
void salvar_estoque(Produto *produtos, int total_produtos);
void carregar_estoque(Produto *produtos, int *total_produtos);


// Função principal que controla o fluxo do programa
int main() {
    Produto produtos[MAX_PRODUTOS];  // Cria um array para armazenar os produtos
    int total_produtos = 0;  // Inicializa o total de produtos no estoque como 0

    carregar_estoque(produtos, &total_produtos);  // Carrega o estoque do arquivo no início do programa

    int opcao;
    do {
        // Exibe o menu de opções para o usuário
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Salvar e Sair\n");
        printf("Escolha uma opção: ");
        opcao = ler_inteiro();  // Lê a escolha do usuário, garantindo que seja um número inteiro

        switch (opcao) {
            case 1:
                adicionar_produto(produtos, &total_produtos);  // Adiciona um novo produto ao estoque
                break;
            case 2:
                listar_produtos(produtos, total_produtos);  // Lista os produtos no estoque
                break;
            case 3:
                salvar_estoque(produtos, total_produtos);  // Salva o estoque e encerra o programa
                printf("Estoque salvo. Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");  // Exibe mensagem para opção inválida
        }
    } while (opcao != 3);  // Repete o loop até que o usuário escolha a opção de sair

    return 0;  // Finaliza o programa
}
