//
// Created by Manara on 23/10/2024.
//

#include "funcoes.h"

// Função para ler um número inteiro do usuário, garantindo entrada válida
int ler_inteiro() {
    int valor;
    while (1) {
        if (scanf("%d", &valor) == 1) {  // Verifica se a entrada foi um inteiro
            return valor;  // Se válido, retorna o valor
        } else {
            printf("Entrada inválida! Por favor, insira um número inteiro: ");
            while (getchar() != '\n');  // Limpa o buffer do teclado para evitar loops infinitos
        }
    }
}

// Função para ler um número decimal (float) do usuário, garantindo entrada válida
float ler_float() {
    float valor;
    while (1) {
        if (scanf("%f", &valor) == 1) {  // Verifica se a entrada foi um float válido
            return valor;  // Se válido, retorna o valor
        } else {
            printf("Entrada inválida! Por favor, insira um número decimal: ");
            while (getchar() != '\n');  // Limpa o buffer do teclado
        }
    }
}

// Função para adicionar um novo produto ao estoque
void adicionar_produto(Produto *produtos, int *total_produtos) {
    if (*total_produtos < MAX_PRODUTOS) {  // Verifica se ainda há espaço para adicionar mais produtos
        Produto novo_produto;  // Cria uma nova variável para armazenar o novo produto

        // Leitura do ID do produto
        printf("ID do produto: ");
        novo_produto.id = ler_inteiro();  // Garante que o ID será um número inteiro

        // Leitura do nome do produto
        printf("Nome do produto: ");
        scanf(" %[^\n]s", novo_produto.nome);  // Lê o nome do produto até encontrar uma nova linha

        // Leitura do preço do produto
        printf("Preço do produto: ");
        novo_produto.preco = ler_float();  // Garante que o preço será um número decimal

        // Valida se o preço é positivo
        while (novo_produto.preco < 0) {
            printf("Preço não pode ser negativo. Insira um valor positivo: ");
            novo_produto.preco = ler_float();  // Solicita nova entrada se o valor for inválido
        }

        // Leitura da quantidade no estoque
        printf("Quantidade no estoque: ");
        novo_produto.quantidade = ler_inteiro();  // Garante que a quantidade será um número inteiro

        // Valida se a quantidade é positiva
        while (novo_produto.quantidade < 0) {
            printf("Quantidade não pode ser negativa. Insira um valor positivo: ");
            novo_produto.quantidade = ler_inteiro();  // Solicita nova entrada se o valor for inválido
        }

        // Adiciona o novo produto à lista de produtos
        produtos[*total_produtos] = novo_produto;

        // Incrementa o número total de produtos
        (*total_produtos)++;
    } else {
        printf("Estoque cheio!\n");  // Caso o estoque esteja cheio, exibe uma mensagem de erro
    }
}

// Função para listar todos os produtos no estoque
void listar_produtos(Produto *produtos, int total_produtos) {
    printf("---- Lista de Produtos no Estoque ----\n");
    for (int i = 0; i < total_produtos; i++) {  // Percorre todos os produtos no estoque
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);  // Exibe o preço com 2 casas decimais
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("-----------------------------------\n");
    }
}

// Função para salvar o estoque de produtos em um arquivo
void salvar_estoque(Produto *produtos, int total_produtos) {
    FILE *arquivo = fopen("estoque.txt", "w");  // Abre o arquivo "estoque.txt" para escrita
    if (arquivo == NULL) {  // Verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo para gravação!\n");
        return;  // Sai da função se o arquivo não pôde ser aberto
    }

    // Grava cada produto no arquivo
    for (int i = 0; i < total_produtos; i++) {
        fprintf(arquivo, "%d %s %.2f %d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    fclose(arquivo);  // Fecha o arquivo após a gravação
}

// Função para carregar o estoque de produtos a partir de um arquivo
void carregar_estoque(Produto *produtos, int *total_produtos) {
    FILE *arquivo = fopen("estoque.txt", "r");  // Abre o arquivo "estoque.txt" para leitura
    if (arquivo == NULL) {  // Verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;  // Sai da função se o arquivo não pôde ser aberto
    }

    // Lê cada linha do arquivo e carrega os dados para o array de produtos
    while (fscanf(arquivo, "%d %s %f %d", &produtos[*total_produtos].id, produtos[*total_produtos].nome,
                  &produtos[*total_produtos].preco, &produtos[*total_produtos].quantidade) != EOF) {
        (*total_produtos)++;  // Incrementa o total de produtos para cada linha lida
    }

    fclose(arquivo);  // Fecha o arquivo após a leitura
}