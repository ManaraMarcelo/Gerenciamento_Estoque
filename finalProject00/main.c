#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf, etc.)
#include "funcoes.h" // Biblioteca autoral para manuseio das funcoes.

#define MAX_PRODUTOS 100  // Define o número máximo de produtos no estoque

// Protótipos das funções que serão utilizadas no programa
void adicionar_produto(Produto *produtos, int *total_produtos);   // Função para adicionar produto
void atualizar_produto(Produto *produtos, int total_produtos);     // Função para atualizar produto
void listar_estoque(Produto *produtos, int total_produtos);        // Função para listar produtos no estoque
void salvar_estoque(Produto *produtos, int total_produtos);        // Função para salvar estoque em arquivo
void carregar_estoque(Produto *produtos, int *total_produtos);     // Função para carregar estoque de arquivo

int main() {
    Produto produtos[MAX_PRODUTOS];  // Array que vai armazenar os produtos
    int total_produtos = 0;          // Contador de quantos produtos estão cadastrados
    int opcao;                       // Variável para armazenar a escolha do usuário no menu

    carregar_estoque(produtos, &total_produtos);  // Carrega o estoque salvo do arquivo, se existir

    do {
        // Exibe o menu de opções para o usuário
        printf("\n......... Menu .........\n");
        printf("1. Adicionar Produto\n");
        printf("2. Atualizar Produto\n");
        printf("3. Listar Estoque\n");
        printf("4. Salvar Estoque e Sair\n");
        printf("........................\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);  // Lê a opção do usuário

        // Switch para realizar a ação escolhida
        switch(opcao) {
            case 1:
                adicionar_produto(produtos, &total_produtos);  // Chama função para adicionar produto
                break;
            case 2:
                atualizar_produto(produtos, total_produtos);   // Chama função para atualizar um produto existente
                break;
            case 3:
                listar_estoque(produtos, total_produtos);      // Chama função para listar os produtos
                break;
            case 4:
                salvar_estoque(produtos, total_produtos);      // Salva o estoque em um arquivo e sai
                printf("Estoque salvo com sucesso!\n");
                break;
            default:
                printf("Opção inválida!\n");  // Se a opção for inválida, exibe uma mensagem de erro
        }
    } while (opcao != 4);  // Repete o menu até que o usuário escolha a opção de sair

    return 0;  // Termina o programa
}

